/*************************************************************************
 > File Name: fifo_cs.h
 > Created Time: 2019年08月28日 星期三 23时41分24秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/sem.h>
#include<sys/msg.h>
#include<string.h> 

int fifo_read(char *data, int *data_len, char sig);

int fifo_write(char *data, int data_len, char sig);


