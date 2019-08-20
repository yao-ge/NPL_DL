/*************************************************************************
  > File Name: server.c
  > Created Time: 2019年08月14日 星期三 04时29分39秒
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


int32_t server_s()
{
	int32_t ret = 0;
	struct sockaddr_in local_addr;
	int32_t len = 0;
	int32_t i = 0;
	uint8_t buf[2048] = {0};
	static int32_t ctrl_port = 9090;
	static int32_t sockfd = -1;
	// 初始化 tcp
	local_addr.sin_family=AF_INET; //设置为IP通信
	local_addr.sin_addr.s_addr=INADDR_ANY;//服务器IP地址--允许连接到所有本地地址上
	local_addr.sin_port=htons(ctrl_port); //服务器端口号

	/*创建服务器端套接字--IPv4协议，TCP协议*/
	if((sockfd=socket(PF_INET,SOCK_STREAM,0))<0)  {
		perror("socket");
		printf("\tInitialization SOCKET failed\n") ;
		return -1;
	}

	/*将套接字绑定到服务器的网络地址上*/
	int opt =SO_REUSEADDR;
	setsockopt(sockfd,SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	if (bind(sockfd,(struct sockaddr *)&local_addr,sizeof(struct sockaddr))<0)  {
		perror("bind");
		printf("\tBind SOCKET failed...     bind_port:%d\n",ctrl_port) ;
		return -1;
	}
	printf("\tBind SOCKET  port:%d   done\n",ctrl_port) ;

	//listen，成功返回0，出错返回-1
	if (listen(sockfd, 10) == -1) {
		perror("listen");
		printf("\tListen SOCKET failed...\n") ;
		return -1;
	}
	printf("\tListen SOCKET on:%d...\n",ctrl_port) ;

	while(1) {
		int32_t  length = sizeof(local_addr);
		int32_t  conn = accept(sockfd, (struct sockaddr*)&local_addr, (socklen_t *)&length);

		if (conn < 0) {
			return -1;
		}

		while (1) {

			//printf("remote host:%s:%d  is connected...\n",inet_ntoa(local_addr.sin_addr),ntohs(local_addr.sin_port)) ;

			memset(buf, 0x00, sizeof buf);
			len = recv(conn,buf, 65535, 0) ;
			if (len <= 0) {
				break;
			}

			/*
			for(i = 0; i < len; i++){
				if(i % 32 == 0 && i != 0){
					printf("\n");
				}
				printf("%02x ", buf[i]);
			}
			printf("\n");
			*/
			len = send(conn, buf, len, 0);
		}
		close(conn);
	}

	close(sockfd) ;

	return ret;
}

int32_t main()
{
	server_s();
	return 0;
}
