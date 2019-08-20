/*************************************************************************
  > File Name: client.c
  > Created Time: 2019年08月14日 星期三 04时48分01秒
 ************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

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


int32_t client_s()
{
	int ret = 0;
	int32_t i = 0;
	uint8_t ch_cmd[4096] = {0};
	memset(&ch_cmd[68], 0x55, 4028);
	uint8_t ch_cmd1[4096] = {0};
	int32_t pkt_len = 0;
	uint8_t allmac[6] = {0x00, 0x00, 0x00, 0x00, 0x01, 0x01};
	uint8_t dip[6] = {0x01, 0x02, 0x03, 0x04};
	uint8_t sip[6] = {0x05, 0x06, 0x07, 0x08};
	int32_t remote_port = 9090;
	static char remote_addr[32];
	snprintf(remote_addr, 32, "127.0.0.1");
	int32_t sockd = -1;

	struct header_t *header = (struct header_t *)&ch_cmd[pkt_len];
	int32_t header_len = sizeof(struct header_t);
	pkt_len += header_len;

	struct Ether_t *Ether = (struct Ether_t *)&ch_cmd[pkt_len];
	int32_t ether_len = sizeof(struct Ether_t);
	pkt_len += ether_len;

	//struct vlan_t outer_tag;
	//struct vlan_t inner_tag;
	//int32_t vlan_len = sizeof(struct vlan_t);
	//memset(&outer_tag, 0x00, vlan_len);
	//memset(&inner_tag, 0x00, vlan_len);
	
	struct ipv4_t *ipv4 = (struct ipv4_t*)&ch_cmd[pkt_len];
	int32_t ipv4_len = sizeof(struct ipv4_t);
	pkt_len += ipv4_len;

	struct udp_t *udp = (struct udp_t*)&ch_cmd[pkt_len];
	int32_t udp_len = sizeof(struct udp_t);
	pkt_len += udp_len;

	header->opcode[3] = 0x0b;
	header->port[3] = 0;
	//header->pkt_len[3] = pkt_len - header_len;
	header->pkt_len = htonl(2104);
	//memcpy(&ch_cmd[pkt_len], &header, header_len);
	//pkt_len += header_len;


	// smac dmac eth_type
	memcpy(Ether->dmac, allmac, 6);
	memcpy(Ether->smac, allmac, 6);
	Ether->eth_type = 0x0008;
	//memcpy(&ch_cmd[pkt_len], &Ether, ether_len);
	//pkt_len += ether_len;

	// ipv4
	ipv4->version = 5;
	ipv4->hdr_len = 4;
	ipv4->v4_length = htons(20 + 8 + 2048 + 14);
	ipv4->id = htons(1);
	ipv4->ttl = 64;
	ipv4->protocol = 0x11;
	memcpy(ipv4->dip, dip, 4);
	memcpy(ipv4->sip, sip, 4);

	//memcpy(&ch_cmd[pkt_len], &ipv4, ipv4_len);
	//pkt_len += ipv4_len;
	
	// udp
	udp->sport = htons(0x35);
	udp->dport = htons(0x35);
	udp->length = htons(0x08 + 2048 + 14);
	//memcpy(&ch_cmd[pkt_len], &udp, udp_len);
	//pkt_len += udp_len;


	sockd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockd < 0) {
		printf("socket create fail\n");
		ret = -1;
		return ret;
	}

	struct sockaddr_in servaddr;
	memset(&servaddr, 0x00, sizeof servaddr);
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(remote_addr);
	servaddr.sin_port = htons(remote_port);
	printf("ip: %s, port: %d\n", remote_addr, remote_port);
	if (connect(sockd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
		printf("socket connect fail\n");
		ret = -2;
		close(sockd);
		return ret;
	}

	while(1){
		printf("send:\n");
		for(i = 0; i < 2116; i++){
			if(i % 16 == 0 && i != 0){
				printf("\n");
			}else if(i % 8 == 0 && i != 0){
				printf("\t");
			}
			printf("%02x ", ch_cmd[i]);
		}
		printf("\n");
		printf("\n");

		int n = send(sockd, ch_cmd, 2116, 0);
		n = recv(sockd, ch_cmd1, 65535, 0);
		printf("recv:%d\n", n);
		/*
		for(i = 0; i < 256; i++){
			if(i % 16 == 0 && i != 0){
				printf("\n");
			}else if(i % 8 == 0 && i != 0){
				printf("\t");
			}
			printf("%02x ", ch_cmd1[i]);
		}
		printf("\n");
		*/
		break;
	}

	close(sockd);
	return ret;
}

int32_t main()
{
	client_s();
	return 0;
}
