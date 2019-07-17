#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#define PATH_NAME "/tmp"    //一个路径
#define PRJ_ID 0X666  	
#define SIZE 4096

int main()
{
	key_t k = ftok(PATH_NAME, PRJ_ID);
	if(k < 0){
		printf("ftok error!\n");
		return 1;
	}
	
	int shm_id = shmget(k, SIZE, 0);		//生成共享内存，看到同一块内存,    返回值为共享内存的标识符,SIZE为共享内存的大小
	if(shm_id < 0){
		printf("shmget error!\n");
		return 2;
	}
	char *p = (char*)shmat(shm_id, NULL, 0);      //挂接     成功后返回值为内存的起始地址  
	int i = 0;
	while(i < SIZE)
	{
		p[i] = 'a' + i;
		i++;
		p[i] = 0;		//字符串结尾
		sleep(1);
	}

	shmdt(p); 									//结束时去关联
	return 0;
}
