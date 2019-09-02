/*************************************************************************
 > File Name: fifo_cs.c
 > Created Time: 2019年08月30日 星期五 04时24分23秒
 ************************************************************************/

#include "fifo_cs.h"

char key_sig[4] = {'a', 'b', 'c', 'd'};

// 消息队列结构
struct msg_form {
    long mtype;
	int  mlength;
    char mtext;
};

// 联合体，用于semctl初始化
union semun
{
    int              val; /*for SETVAL*/
    struct semid_ds *buf;
    unsigned short  *array;
};

// 初始化信号量
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

// P操作:
//  若信号量值为1，获取资源并将信号量值-1 
//  若信号量值为0，进程挂起等待
int sem_p(int sem_id)
{
	//printf("call sem p\n");
    struct sembuf sbuf;
    sbuf.sem_num = 0; /*序号*/
    sbuf.sem_op = -1; /*P操作*/
    sbuf.sem_flg = SEM_UNDO;

	//printf("sem id:%d\n", sem_id);
    if(semop(sem_id, &sbuf, 1) == -1)
    {
        perror("P operation Error");
        return -1;
    }
	//printf("end sem p\n");
    return 0;
}

// V操作：
//  释放资源并将信号量值+1
//  如果有进程正在挂起等待，则唤醒它们
int sem_v(int sem_id)
{
	//printf("call sem v\n");
    struct sembuf sbuf;
    sbuf.sem_num = 0; /*序号*/
    sbuf.sem_op = 1;  /*V操作*/
    sbuf.sem_flg = SEM_UNDO;

    if(semop(sem_id, &sbuf, 1) == -1)
    {
        perror("V operation Error");
        return -1;
    }
	//printf("end sem v\n");
    return 0;
}

// 删除信号量集
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

// 创建一个信号量集
int creat_sem(key_t key)
{
    int sem_id;
    if((sem_id = semget(key, 1, IPC_CREAT|0666)) == -1)
    {
        perror("semget error");
        exit(-1);
    }
    init_sem(sem_id, 2);  /*初值设为1资源未占用*/
    return sem_id;
}

int fifo_reset()
{
    key_t key;
	char sig = 'r';
    int shmid, semid, msqid;
    struct shmid_ds buf1;  /*用于删除共享内存*/
    struct msqid_ds buf2;  /*用于删除消息队列*/
    char *shm;
	int key_nums = 4;
	int i = 0;

	for(i = 0; i < key_nums; i++){
		// 获取key值
    	if((key = ftok(".", key_sig[i])) < 0)
    	{
    	    perror("ftok error");
    	    exit(1);
    	}
		//printf("get key\n");

    	// 获取共享内存
    	//if((shmid = shmget(key, 4096, 0)) == -1)
    	if((shmid = shmget(key, 4096, IPC_CREAT|0666)) == -1)
    	{
			//printf("aaa\n");
    	    perror("shmget error");
    	    exit(1);
    	}
		//printf("get shmid\n");

    	// 连接共享内存
    	shm = (char*)shmat(shmid, 0, 0);
    	if((int)*shm == -1)
    	{
    	    perror("Attach Shared Memory Error");
    	    exit(1);
    	}
		//printf("get shm\n");

    	// 创建消息队列
    	//if ((msqid = msgget(key, 0)) == -1)
    	if ((msqid = msgget(key, IPC_CREAT|0777)) == -1)
    	{
    	    perror("msgget error");
    	    exit(1);
    	}
		//printf("get msqid\n");

    	// 获取信号量
    	if((semid = semget(key, 0, 0)) == -1)
    	{
			if((semid = semget(key, 1, IPC_CREAT|0666)) == -1){
				perror("semget error");
				exit(1);
			}
			init_sem(semid, 2);
    	}

		memset(shm, 0x00, 4096);
    	// 断开连接
    	shmdt(shm);

    	/*删除共享内存、消息队列、信号量*/
    	shmctl(shmid, IPC_RMID, &buf1);
    	msgctl(msqid, IPC_RMID, &buf2);
    	//del_sem(semid);
	}

	return 0;

}


int fifo_read(char *data, int data_len, int key_lable)
{
    key_t key;
    int shmid, semid, msqid;
    char *shm;
    struct shmid_ds buf1;  /*用于删除共享内存*/
    struct msqid_ds buf2;  /*用于删除消息队列*/
    struct msg_form msg;  /*消息队列用于通知对方更新了共享内存*/
	memset(&msg, 0x00, sizeof(struct msg_form));
	int read_count = 0;

    // 获取key值
    if((key = ftok(".", key_sig[key_lable])) < 0)
    {
        perror("ftok error");
        exit(1);
    }
	//printf("get key\n");

    // 创建共享内存
    if((shmid = shmget(key, 4096, IPC_CREAT|0666)) == -1)
    {
        perror("Create Shared Memory Error");
        exit(1);
    }
	//printf("get shmid\n");

    // 连接共享内存
    shm = (char*)shmat(shmid, 0, 0);
    if((int)*shm == -1)
    {
        perror("Attach Shared Memory Error");
        exit(1);
    }
	//printf("get shm\n");


    // 创建消息队列
    if ((msqid = msgget(key, IPC_CREAT|0777)) == -1)
    {
        perror("msgget error");
        exit(1);
    }
	//printf("get msqid\n");

    // 创建信号量
    if((semid = semget(key, 0, 0)) == -1)
    {
		if((semid = semget(key, 1, IPC_CREAT|0666)) == -1){
			perror("semget error");
			exit(1);
		}
		//printf("get semid inside\n");
		init_sem(semid, 2);
    }
	//printf("get semid outside\n");
    //semid = creat_sem(key);
    
#if 1
    // 读数据
    while(1)
    {
        msgrcv(msqid, &msg, sizeof(struct msg_form), 888, IPC_NOWAIT); /*读取类型为888的消息*/
        if(msg.mtext == 'r')  /*read - 读共享内存*/
        {
            //sem_p(semid);
			memcpy(data, shm, msg.mlength);
			data_len = msg.mlength;
            //sem_v(semid);
			break;
        }
		if(100 < (read_count++)){
			break;
		}
		usleep(20);
    }
#else

	while(1){
		int i = 0;
		for(i = 0; i < 128; i++){
			if(i != 0 && i % 16 == 0){
				printf("\n");
			}else if(i != 0 && i % 8 == 0)
				printf("\t");
			printf("%02x ", shm[i]);
		}

		printf("\n");
		if(shm[28] == 0x01){
			memcpy(data, shm, data_len);
			memset(shm, 0x00, 4096);
			break;
		}
	}
#endif

    // 断开连接
    shmdt(shm);

    /*删除共享内存、消息队列、信号量*/
    //shmctl(shmid, IPC_RMID, &buf1);
    //msgctl(msqid, IPC_RMID, &buf2);
    //del_sem(semid);
    return 0;
}


int fifo_write(char *data, int data_len, int key_lable)
{
    key_t key;
	char sig = 'r';
    int shmid, semid, msqid;
    char *shm;
    struct msg_form msg;
	memset(&msg, 0x00, sizeof(struct msg_form));
    int flag = 1; /*while循环条件*/

    // 获取key值
    if((key = ftok(".", key_sig[key_lable])) < 0)
    {
        perror("ftok error");
        exit(1);
    }
	//printf("get key\n");

    // 获取共享内存
    //if((shmid = shmget(key, 4096, 0)) == -1)
    if((shmid = shmget(key, 4096, IPC_CREAT|0666)) == -1)
    {
		//printf("aaa\n");
        perror("shmget error");
        exit(1);
    }
	//printf("get shmid\n");

    // 连接共享内存
    shm = (char*)shmat(shmid, 0, 0);
    if((int)*shm == -1)
    {
        perror("Attach Shared Memory Error");
        exit(1);
    }
	//printf("get shm\n");

    // 创建消息队列
    //if ((msqid = msgget(key, 0)) == -1)
    if ((msqid = msgget(key, IPC_CREAT|0777)) == -1)
    {
        perror("msgget error");
        exit(1);
    }
	//printf("get msqid\n");

    // 获取信号量
    if((semid = semget(key, 0, 0)) == -1)
    {
		if((semid = semget(key, 1, IPC_CREAT|0666)) == -1){
			perror("semget error");
			exit(1);
		}
		init_sem(semid, 2);
    }
	//printf("get semid\n");
    
#if 1
    while(flag)
    {
        switch(sig)
        {
            case 'r':
				//printf("before call sem_p:%d\n", semid);
                //sem_p(semid);  /*访问资源*/
				//printf("call sem_p\n");
				memcpy(shm, data, data_len);
                //sem_v(semid);  /*释放资源*/
				//printf("release sem_v\n");
                msg.mtype = 888;  
				msg.mlength = data_len;
                msg.mtext = 'r';  /*发送消息通知服务器读数据*/
                msgsnd(msqid, &msg, sizeof(struct msg_form), IPC_NOWAIT);
				flag = 1;
                break;
            default:
                //printf("Wrong input!\n");
				break;
        }
		break;
    }
#else

	memcpy(shm, data, data_len);
#endif
	

    // 断开连接
    shmdt(shm);
	//printf("break shmdt\n");

    return 0;
}
