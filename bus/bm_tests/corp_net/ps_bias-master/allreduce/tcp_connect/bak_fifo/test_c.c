/*************************************************************************
 > File Name: test_c.c
 > Created Time: 2019年08月28日 星期三 23时43分56秒
 ************************************************************************/

#include "fifo_cs.h"


int main()
{
	int ret = 0;
	char data[128] = {0};
	int data_length = 12;
	int i = 0;
	for(i = 0; i < data_length; i++)
		data[i] = i;

	fifo_write(data, data_length, 'r');

	return ret;
}
