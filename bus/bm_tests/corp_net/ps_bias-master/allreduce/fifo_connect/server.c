/*************************************************************************
 > File Name: server.c
 > Created Time: 2019年08月30日 星期五 04时26分55秒
 ************************************************************************/

#include "fifo_cs.h"

int main()
{
	int ret = 0;
	char data[12] = {0};
	int data_len = 0;
	ret = fifo_read(data, &data_len);
	int i = 0;
	printf("data len:%d\n", data_len);
	for(i = 0; i < data_len; i++){
		printf("%02x ", data[i]);
	}
	printf("\n");
	return ret;
}
