/*************************************************************************
 > File Name: test_s.c
 > Created Time: 2019年08月28日 星期三 23时46分52秒
 ************************************************************************/

#include "fifo_cs.h"

int main()
{
	int ret = 0;
	char data[128] = {0};
	int data_length = 0;
	int i = 0;
	fifo_read(data, &data_length, 'r');
	for(i = 0; i < data_length; i++)
		printf("%02x ", data[i]);
	printf("\n");
	return ret;
}
