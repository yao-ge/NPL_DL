/*************************************************************************
 > File Name: client.c
 > Created Time: 2019年08月30日 星期五 04时27分40秒
 ************************************************************************/

#include "fifo_cs.h"

int main()
{
	int ret = 0;
	char data[12] = {0};
	int data_len = 12;
	memset(data, 0x01, 12);
	ret = fifo_write(data, data_len);
	return ret;
}
