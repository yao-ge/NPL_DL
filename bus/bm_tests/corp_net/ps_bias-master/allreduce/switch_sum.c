#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <mpi.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "debug.h"
#include <math.h>
#include <float.h>
#include <python3.5m/Python.h>


#define __USE_GNU       //..CPU_ZERO.....
//#define _GNU_SOURCE
#include <sched.h>
#include <pthread.h>      //........__USE_GNU.............CPU_ZERO...


#define BIT_WIDTH 16

// when BIT_WIDTH == 32 , precision is enough to train
// when BIT_WIDTH == 64 , precision is enough to train well
// the defination of MAX_BASE == 1. can only train module with activation function sigmoid(); 

#if BIT_WIDTH == 16
	#define BYTES 2
    #define BLOCK_SIZE 1024 // 32740
    //#define EXPAND  65536.
    #define EXPAND  32767.
    #define MAX_BASE  1.
    #define HTON htons
    #define NTOH ntohs
    typedef unsigned short data_t;
#elif BIT_WIDTH == 32
	#define BYTES 4
    #define BLOCK_SIZE 16371
    #define EXPAND  2147483648.
    #define MAX_BASE  1.
    #define HTON htonl
    #define NTOH ntohl
    typedef unsigned int data_t;
#elif BIT_WIDTH == 64
	#define BYTES 8
    #define BLOCK_SIZE 8185
    #define EXPAND  9223372036854775808.
    #define MAX_BASE  10.
    #define HTON htonll
    #define NTOH ntohll
    typedef unsigned long long data_t;
#endif


#define TIMEOUT 100000
#define BUF_SIZE 4096 //  (65535)

#define SERVER_IP   "10.0.2.2"
#define SERVER_PORT "1111"



struct header_t {
	uint8_t opcode[4];
	uint8_t port[4];
	uint32_t pkt_len;
}__attribute__((__packed__));

struct Ether_t {
	uint8_t dmac[6];
	uint8_t smac[6];
	uint16_t eth_type;
}__attribute__((__packed__));

struct vlan_t {
	uint16_t vlan_id;
	uint16_t eth_type;
}__attribute__((__packed__));

struct ipv4_t {
	uint8_t version:4;
	uint8_t hdr_len:4;
	uint8_t tos;
	uint16_t v4_length;
	uint16_t id;
	uint16_t flags:3;
	uint16_t flags_offset:13;
	uint8_t ttl;
	uint8_t protocol;
	uint16_t hdr_checksum;
	uint8_t sip[4];
	uint8_t dip[4];
}__attribute__((__packed__));

struct udp_t {
	uint16_t sport;
	uint16_t dport;
	uint16_t length;
	uint16_t checksum;
	uint16_t job_id;
	uint16_t max_worker;
	uint16_t worker_id;
	uint16_t sequence;
	uint16_t exp;
	uint16_t bias;
	uint16_t bias_exp;
}__attribute__((__packed__));


int32_t padding_header_to_buf(char *buf, int32_t *pkt_len, int32_t data_len, \
		int key, int size, int rank, int block, short exp, short bias, short bias_exp)
{
	int32_t ret = 0;

	uint8_t allmac[6] = {0x00, 0x00, 0x00, 0x00, 0x01, 0x01};
	uint8_t dip[6] = {0x01, 0x02, 0x03, 0x04};
	uint8_t sip[6] = {0x05, 0x06, 0x07, 0x08};

	struct header_t *header = (struct header_t *)&buf[*pkt_len];
	int32_t header_len = sizeof(struct header_t);
	*pkt_len += header_len;

	struct Ether_t *Ether = (struct Ether_t *)&buf[*pkt_len];
	int32_t ether_len = sizeof(struct Ether_t);
	*pkt_len += ether_len;

	struct ipv4_t *ipv4 = (struct ipv4_t*)&buf[*pkt_len];
	int32_t ipv4_len = sizeof(struct ipv4_t);
	*pkt_len += ipv4_len;

	struct udp_t *udp = (struct udp_t*)&buf[*pkt_len];
	int32_t udp_len = sizeof(struct udp_t);
	*pkt_len += udp_len;

	header->opcode[3] = 0x0b;
	header->port[3] = 0;
	//header->pkt_len = htonl(BUF_SIZE + ether_len + ipv4_len + udp_len);
	header->pkt_len = htonl(2048 + ether_len + ipv4_len + udp_len);

	// smac dmac eth_type
	memcpy(Ether->dmac, allmac, 6);
	memcpy(Ether->smac, allmac, 6);
	Ether->eth_type = 0x0008;

	// ipv4
	ipv4->version = 5;
	ipv4->hdr_len = 4;
	ipv4->v4_length = htons(20 + 8 + data_len);
	ipv4->id = htons(1);
	ipv4->ttl = 64;
	ipv4->protocol = 0x11;
	memcpy(ipv4->dip, dip, 4);
	memcpy(ipv4->sip, sip, 4);

	// udp
	udp->sport = htons(0x35);
	udp->dport = htons(0x35);
	udp->length = htons(0x08 + data_len);
	udp->job_id = htons(key);
	udp->max_worker = htons(size);
	udp->worker_id = htons(rank);
	udp->sequence = htons(block);
#if 1
	//printf("exp:%d, bias:%d, bias exp:%d\n", exp, bias, bias_exp);
	udp->exp = htons(exp);
	udp->bias = htons(bias);
	udp->bias_exp = htons(bias_exp);

	printf("job id:%d, max_worker:%d, worker_id:%d, sequence:%d, exp:%d, bias:%d, bias_exp:%d\n",
			//udp->job_id, udp->max_worker, udp->worker_id, udp->sequence, udp->exp, udp->bias, udp->bias_exp);
			key, size, rank, block, exp, bias, bias_exp);
#endif
	return ret;
}

#if 1
void print_floats(const float *data, int count)
{
    printf("floats: ");
    for(int i=0;i < count ; ++i){
        printf("%.10lf  ", data[i]);
    }
    printf("\n");

}

void print_data(const data_t *data, int count)
{
    printf("data: ");
    for(int i=0;i < count ; ++i){
        printf("%llu  ", (unsigned long long)data[i]);
    }
    printf("\n");

}

void print_chars(const char *data, int count)
{
    for(int i=0;i < count ; ++i){
		if(i % 16 == 0 && i != 0){
			printf("\n");
		}else if(i % 8 == 0 && i != 0){
			printf("\t");
		}
        printf("%02x ", (unsigned char)data[i]);
    }
    printf("\n");

}

int sock = 0;
struct sockaddr_in sock_addr;
void socket_init(const char* ip, const char* port)
{
    //if ( (sock = socket(AF_INET, SOCK_DGRAM, 0) ) < 0 )
    if ( (sock = socket(AF_INET, SOCK_STREAM, 0) ) < 0 )
	{
		perror("socket");
		exit(1);
	}

	sock_addr.sin_family = AF_INET;
	sock_addr.sin_port = htons(atoi(port));
	sock_addr.sin_addr.s_addr = inet_addr(ip);
	if ( sock_addr.sin_addr.s_addr == INADDR_NONE )
	{
		printf("Incorrect ip address!");
		close(sock);
		exit(1);
	}

    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = TIMEOUT;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

	int breuseaddr = 1;
    setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (const char *)&breuseaddr, sizeof(int));

	if((connect(sock, (struct sockaddr *)&sock_addr, sizeof(sock_addr)) < 0)) {
		printf("socket connect failed\n");
	}

}

void socket_close()
{
    close(sock);
}

int send_recv(int key, data_t *data, int count, int block, int size, int rank, short *exp, short *bias, short *bias_exp)
{
//	printf("This is a UDP client\n");
	char buff[BUF_SIZE] = {0};
	int len = sizeof(sock_addr);
	int pkt_len = 0;

#if BIT_WIDTH == 4
	int data_len = count/2 + count%2;
	int block_len = BLOCK_SIZE/2 + sizeof(short) * 7;
#else
	int data_len = BYTES * count ;
	//int block_len = BYTES * BLOCK_SIZE + sizeof(short) * 7;
	int block_len = BYTES * BLOCK_SIZE;
#endif

	padding_header_to_buf(buff, &pkt_len, data_len, key, \
			size, rank, block, *exp, *bias, *bias_exp);

	if(0 < data_len){
		memcpy( buff+ pkt_len, (char*)&data, data_len );
	}
	block_len += pkt_len;

    //printf("sent block len:%d, data len:%d\n", block_len, data_len);
    //print_chars(buff, 128);
    //int n = sendto(sock, buff, block_len, 0, (struct sockaddr *)&sock_addr, sizeof(sock_addr));
	int n = send(sock, buff, block_len, 0);
	if (n < 0)
	{
		perror("sendto");
		printf("n:%d, sock:%d\n", n, sock);
		exit(0);
		//close(sock);
		return -1;
	}

	while(1){
		//n = recvfrom(sock, buff, 65535, 0, (struct sockaddr *)&sock_addr,  (socklen_t*)&len);
		n = recv(sock, buff, 65535, 0);
		if(n > 0)
			break;
	}
    printf("recv block len:%d\n", n);
    print_chars(buff, 128);
	if (n>0 && data_len != 0)
	{
		//buff[n] = 0;
		//printf("received:");
		//puts(buff);
        short v;
	    memcpy( (char*)&v, buff+ pkt_len + 2 + 8,  2 );
        *exp = ntohs(v);
	    memcpy( (char*)&v, buff+ pkt_len + 2 + 10, 2 );
        *bias = ntohs(v);
	    memcpy( (char*)&v, buff+ pkt_len + 2 + 12, 2 );
        *bias_exp = ntohs(v);
	    memcpy( (char*)data, buff+ pkt_len + 2 + 14, data_len );
	}
	else if (n==0)
	{
		printf("server closed\n");
		//close(sock);
		return -1;
	}
	else if (n == -1)
	{
		perror("recvfrom send");
		//close(sock);
		return -1;
	}
    //close(sock);
	return 0;
}


int block_int_sum(int key, data_t *data, int count, int block, int size, int rank, short * exp, short * bias, short * bias_exp)
{
    //log_print( ">%d     %d\n", counter++, count);
    //printf( ">%d     %d     %d    %d\n", counter, count, size, rank);
	while(1){
        int ret = send_recv( key, data, count, block, size, rank, exp, bias, bias_exp );
        if( ret == 0 ) break;
		else printf("reture value:%d\n", ret);
    }
    //log_print( "<%d     %d\n", counter++, count);
    //printf( "<%d     %d     %d    %d\n", counter++, count, size, rank);
	return 0;
}

int block_reset(int key, int size, int rank)
{
    short block = -1;
	short exp = 0;
	short bias = 0;
	short bias_exp = 0;
    while(1){
        //int ret = send_reset(key, size, rank, block);
        int ret = send_recv(key, NULL, 0, block, size, rank, &exp, &bias, &bias_exp);
        if( ret == 0 ) break;
        block--;
    }
}

unsigned long long ntohll(unsigned long long val)
{
    return (((unsigned long long )htonl((int)((val << 32) >> 32))) << 32) | (unsigned int)htonl((int)(val >> 32));
}

unsigned long long htonll(unsigned long long val)
{
    return (((unsigned long long )htonl((int)((val << 32) >> 32))) << 32) | (unsigned int)htonl((int)(val >> 32));
}
#if 1
void xxx( const char *fmt, ...){}
void xxxx(const data_t *data, int count){}
void xxxxx(const float *data, int count){}
//#define printf xxx
#define print_data xxxx
#define print_floats xxxxx
#endif

int block_sum(int key, const float *input, float *output, int count, int block, int size, int rank, float min, float max)
{
	data_t tmp[BLOCK_SIZE];
	data_t tmp_x[BLOCK_SIZE];
    //printf("[DEBUG] in: [%d] ", block);
    print_floats( input ,count);
    //double expand = (double)(EXPAND) / (double)MAX_BASE / size * 0.999999;

    //double bias = (double)MAX_BASE;
    double bias = -min;
    //printf("max = %.10lf   min = %.10lf\n", max, min);

    short exp = log(1./(max - min))/log(2);
    exp = (exp > 16)?16:( (exp < -16)? -16: exp );
    //printf( "exp = %d\n", exp);
    double expand = (exp>=0)? (double)((long long)EXPAND << exp) / size : (double)((long long)EXPAND >> (- exp)) / size ;

    short bias_exp = log(1./fabs(bias))/log(2);
    bias_exp = (bias_exp > 16)?16:( (bias_exp < -16)? -16: bias_exp );
    //printf( "bias_exp = %d\n", bias_exp);
    double bias_expand = (bias_exp>=0)? (double)((long long)EXPAND << bias_exp) / size : (double)((long long)EXPAND >> (- bias_exp)) / size ;

    //double expand = (double)(EXPAND * pow(2, exp)) / size;
    //printf( "expand = %.10lf   bias = %.10lf \n", expand, bias);
    //printf( "count = %d \n", count);
    double bias_x = bias * bias_expand; 
    //printf( "bias_x = %lf\n", bias_x);
	for (int i = 0; i < count; ++i){
        //float value = input[i];
        double value = input[i];

        //tmp_x[i] = (data_t)(value*expand + bias_x + 0.5 );
        tmp_x[i] = (data_t)((value + bias)*expand  );
        tmp[i] = HTON((data_t)((value + bias)*expand  ));
        
        //printf( "value = %.10lf  expand = %.10lf  bias_x = %.10lf tmp_x[i] = 0x%04x\n", value, expand, bias_x, tmp_x[i]);
        //tmp[i] = HTON((data_t)(((double)input[i])*expand) + (data_t)((double)bias*expand) + 0.5);

        //printf("%f %f %x\n", rate,expand,tmp[i]);
        //printf("%llu ", tmp[i]);

    }
    //printf("------------------------\n");
    print_data( tmp_x ,count);
    //print_chars( (char*)tmp, count);
    
    short bias_out = bias_x;
	block_int_sum(key, tmp, count, block, size, rank, &exp, &bias_out, &bias_exp);
    printf( "exp = %d    bias_out = %d  bias_exp = %d\n", exp, bias_out, bias_exp);

	for (int i = 0; i < count; ++i){
        tmp_x[i] = NTOH(tmp[i]);
    }
    print_data( tmp_x ,count);

    expand = (exp>=0)? (double)((long long)EXPAND << exp) / size : (double)((long long)EXPAND >> (- exp)) / size ;
    bias_expand = (bias_exp>=0)? (double)((long long)EXPAND << bias_exp) / size : (double)((long long)EXPAND >> (- bias_exp)) / size ;
    //expand = (double)(EXPAND * pow(2, exp)) / size;
    //print_chars( (char*)tmp, count);
	for (int i = 0; i < count; ++i){
        //printf("%f %f %x\n", rate,expand,tmp[i]);
        output[i] = (float) ((double)NTOH(tmp[i]) / expand - (double)bias_out / bias_expand);

    }

    //printf("[DEBUG] out: [%d] ", block);
    print_floats( output ,count);
	return 0;
} 


void get_min_max(const float *input, int count, float *min_ptr, float *max_ptr){
    float min = FLT_MAX;
    float max = -FLT_MAX;
    for(int i = 0; i< count ;i++){
        if( input[i] < min ) min = input[i];
        if( input[i] > max ) max = input[i];
    }
    //printf("min = %lf    max = %lf \n", min, max);
    *min_ptr = min;
    *max_ptr = max;
}

#if 1
/* Single thread */

int switch_sum(int key, const float *input, float *output, int count, int size, int rank)
{
    socket_init("127.0.0.1","9090");
    //printf("block_reset\n");
    block_reset(key, size, rank); 
    //printf("block_reset done\n");
	float min,max;
    //get_min_max( input, count, &min, &max );
    int block = 0;
#if 1
	for (int i = 0; i < count; i += BLOCK_SIZE)
	{
		if( count - i >= BLOCK_SIZE){
            get_min_max( input + i, BLOCK_SIZE, &min, &max );
			block_sum(key, input + i, output + i, BLOCK_SIZE, block, size, rank, min, max);
            //memcpy( output, input, count*2);
		}
		else{
            get_min_max( input + i, count - i, &min, &max );
			block_sum(key, input + i, output + i, count - i, block, size, rank, min, max);
            //memcpy( output, input, count*2);
		}
        block ++;
	}
#endif
    socket_close();
	return 0;
}
#else
/* Multiple thread */

#define MAX_THREAD 4

typedef struct block_info{
    int key;
	const float* input;
	float *output;
	int	  count;
	int block;
	int size;
	int rank;
	float rate;
}block_info_t;

pthread_t thread_send_recv[MAX_THREAD] = {0};
block_info_t  block_in[MAX_THREAD];

void *block_sum_fun(void *arg)
{
    //pthread_detach(pthread_self());
	block_info_t * bl_in = (block_info_t * )arg;
    /*
    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(0,&mask);
    
    if(sched_setaffinity(0, sizeof(mask), &mask) == -1)      //0 ......./.......
    {
        printf("set affinity failed..");
    }

*/
	block_sum(bl_in->key, bl_in->input, bl_in->output, bl_in->count, bl_in->block, bl_in->size, bl_in->rank, bl_in->rate);
    //memcpy( bl_in->output, bl_in->input, bl_in->count*2);
    //pthread_exit(0);
}

int get_thread(){

    for(int i=0; i<MAX_THREAD; i++)
    {
        if(thread_send_recv[i] == 0) return i;
    }
    for(int i=0; i<MAX_THREAD; i++)
    {
        pthread_join(thread_send_recv[i] , NULL);
        thread_send_recv[i] = 0; 
    }
    return -1;
}

int create( int key, const float *input, float *output, int count, int block, int size, int rank, float rate){
   int err;
    
    int thread_index;
    while((thread_index = get_thread()) == -1)
    {
        usleep(1);
    }

	int index = block % MAX_THREAD;

	block_in[index].key = key;
	block_in[index].input = input;
	block_in[index].output = output;
	block_in[index].count = count;
	block_in[index].block = block;
	block_in[index].size = size;
	block_in[index].rank = rank;
	block_in[index].rate = rate;

	err = pthread_create(&thread_send_recv[index], NULL, block_sum_fun, (void*)&block_in[index]);
	if(err != 0) {
		printf("create thread error: %s\n",strerror(err));
		return 1;
	}

}
int switch_sum(int key, const float *input, float *output, int count, int size, int rank)
{
    socket_init("10.0.2.2","1111");
    block_reset(key, size, rank);
    float rate = get_min_max(input, count);
    int block = 0;
	for (int i = 0; i < count; i += BLOCK_SIZE)
	{
		if( count - i >= BLOCK_SIZE){
			create(key, input + i, output + i, BLOCK_SIZE, block, size, rank, rate);
		}
		else{
			create(key, input + i, output + i, count - i, block, size, rank, rate);
		}
        block ++;
	}

    for (int i = 0; i < MAX_THREAD; i++)
	    if(thread_send_recv[i] != 0)
            pthread_join (thread_send_recv[i], NULL);
    socket_close();
	return 0;
}
#endif

#else

int main()
{
	call_python_interface("ccccc", 5);
	return 0;
}
#endif
