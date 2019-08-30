/*************************************************************************
 > File Name: fifo_cs.c
 > Created Time: 2019年08月28日 星期三 23时07分53秒
 ************************************************************************/

#include "fifo_cs.h"

struct msg_form {
    long mtype;
    char mtext;
};

union semun
{
    int              val; 
    struct semid_ds *buf;
    unsigned short  *array;
};

int init_sem(int sem_id, int value)
{
    union semun tmp;
    tmp.val = value;
    if(semctl(sem_id, 0, SETVAL, tmp) == -1)
    {
        perror("Init Semaphore Error");
        return -1;
    }
    return 0;
}

int sem_p(int sem_id)
{
    struct sembuf sbuf;
    sbuf.sem_num = 0; 
    sbuf.sem_op = -1; 
    sbuf.sem_flg = SEM_UNDO;

    if(semop(sem_id, &sbuf, 1) == -1)
    {
        perror("P operation Error");
        return -1;
    }
    return 0;
}

int sem_v(int sem_id)
{
    struct sembuf sbuf;
    sbuf.sem_num = 0; 
    sbuf.sem_op = 1;  
    sbuf.sem_flg = SEM_UNDO;

    if(semop(sem_id, &sbuf, 1) == -1)
    {
        perror("V operation Error");
        return -1;
    }
    return 0;
}

int del_sem(int sem_id)
{
    union semun tmp;
    if(semctl(sem_id, 0, IPC_RMID, tmp) == -1)
    {
        perror("Delete Semaphore Error");
        return -1;
    }
    return 0;
}

int creat_sem(key_t key)
{
    int sem_id;
    if((sem_id = semget(key, 1, IPC_CREAT|0666)) == -1)
    {
        perror("semget error");
        exit(-1);
    }
    init_sem(sem_id, 1);
    return sem_id;
}

int fifo_read(char *data, int *data_len, char sig)
{
	key_t key;
	int shmid, semid, msqid;
	char *shm;
	struct shmid_ds buf1; 
	struct msqid_ds buf2; 
	struct msg_form msg;  

    if((key = ftok(".", 'z')) < 0)
    {
        perror("ftok error");
        exit(1);
    }

    if((shmid = shmget(key, 4096, IPC_CREAT|0666)) == -1)
    {
        perror("Create Shared Memory Error");
        exit(1);
    }

    shm = (char*)shmat(shmid, 0, 0);
    if((int)*shm == -1)
    {
        perror("Attach Shared Memory Error");
        exit(1);
    }
    
    if ((msqid = msgget(key, IPC_CREAT|0777)) == -1)
    {
        perror("msgget error");
        exit(1);
    }
    
    semid = creat_sem(key);
    
    while(1)
    {
        msgrcv(msqid, &msg, 1, 888, 0); 
        if(msg.mtext == 'q') 
            break;
        if(msg.mtext == 'r') 
        {
            sem_p(semid);
			int i = 0;
			for(i = 0; i < 12; i++){
				printf("%02x ", shm[i]);
			}
			printf("\n");
            //printf("%s\n",shm);
            sem_v(semid);
        }
    }
    
    shmdt(shm);
    
    shmctl(shmid, IPC_RMID, &buf1);
    msgctl(msqid, IPC_RMID, &buf2);
    del_sem(semid);
    return 0;
}

int fifo_write(char *data, int data_len, char sig)
{
	key_t key;
	int shmid, semid, msqid;
	char *shm;
	struct msg_form msg;
	int flag = 1; /*while循环条件*/
	
	// 获取key值
	if((key = ftok(".", 'z')) < 0)
	{
	    perror("ftok error");
	    exit(1);
	}
	
	// 获取共享内存
	if((shmid = shmget(key, 4096, 0)) == -1)
	{
	    perror("shmget error");
	    exit(1);
	}
	
	// 连接共享内存
	shm = (char*)shmat(shmid, 0, 0);
	if((int)*shm == -1)
	{
	    perror("Attach Shared Memory Error");
	    exit(1);
	}
	
	// 创建消息队列
	if ((msqid = msgget(key, 0)) == -1)
	{
	    perror("msgget error");
	    exit(1);
	}
	
	// 获取信号量
	if((semid = semget(key, 0, 0)) == -1)
	{
	    perror("semget error");
	    exit(1);
	}
	
	while(flag)
	{
	    switch(sig)
	    {
	        case 'r':
				printf("send data\n");
	            sem_p(semid);  /*访问资源*/
	            //scanf("%s", shm);
				memcpy(shm, data, data_len);
				int i = 0;
				for(i = 0; i < data_len; i++){
					printf("%02x ", data[i]);
				}
				printf("\n");
				for(i = 0; i < data_len; i++){
					printf("%02x ", shm[i]);
				}
				printf("\n");
	            sem_v(semid);  /*释放资源*/
	            /*清空标准输入缓冲区*/
	            //while((c=getchar())!='\n' && c!=EOF);
	            msg.mtype = 888;
	            msg.mtext = 'r';  /*发送消息通知服务器读数据*/
	            msgsnd(msqid, &msg, sizeof(msg.mtext), 0);
	            break;
	        case 'q':
	            msg.mtype = 888;
	            msg.mtext = 'q';
	            msgsnd(msqid, &msg, sizeof(msg.mtext), 0);
	            flag = 0;
	            break;
	        default:
	            printf("Wrong input!\n");
				printf("%c\n", sig);
	            /*清空标准输入缓冲区*/
	    }
		sleep(100);
	}
	
	// 断开连接
	shmdt(shm);
	
	return 0;
}


