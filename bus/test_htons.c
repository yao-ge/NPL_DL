/*************************************************************************
 > File Name: test_htons.c
 > Created Time: 2019年08月21日 星期三 17时35分19秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>


int32_t main()
{
	int32_t ret = 0;
	printf("0 htons %d\n", ntohs(htons(0)));
	printf("-1 htons %d\n", ntohs(htons(-1)));
	return ret;
}
