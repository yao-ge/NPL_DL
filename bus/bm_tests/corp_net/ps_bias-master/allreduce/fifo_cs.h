/*************************************************************************
 > File Name: fifo_cs.h
 > Created Time: 2019年08月30日 星期五 04时26分22秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>  // shared memory
#include<sys/sem.h>  // semaphore
#include<sys/msg.h>  // message queue
#include<string.h>   // memcpy
#include<unistd.h>

//int fifo_server(char *data, int *data_len);
//
//int fifo_client(char *data, int data_len);
int fifo_read(char *data, int data_len, int key_lable);

int fifo_write(char *data, int data_len, int key_lable);

int fifo_reset();
