#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#define PATH_NAME "/tmp"    //一个路径
#define PRJ_ID 0X666  	
#define SIZE 4096       //bytes         

int main()
{
	key_t k = ftok(PATH_NAME, PRJ_ID);
	if(k < 0){
		printf("ftok error!\n");
		return 1;
	}
	
	int shm_id = shmget(k, SIZE, IPC_CREAT | IPC_EXCL | 0644);		//生成共享内存，看到同一块内存,    返回值为共享内存的标识符,SIZE为共享内存的大小
	if(shm_id < 0){
		printf("shmget error!\n");
		return 2;
	}
	sleep(3);

	char *p = (char*)shmat(shm_id, NULL, 0);      //挂接     成功后返回值为内存的起始地址  
	
	sleep(10);	
	int i = 0;
	while(i < SIZE)
	{
		printf("%s\n", p);
		sleep(1);				//server端读数据打印    client端写数据
	}

	shmdt(p);			//结束时去关联
	sleep(3);
	shmctl(shm_id, IPC_RMID, NULL);           //删共享内存     可 ipcs -m 查看共享内存
	sleep(3);
	return 0;
}
