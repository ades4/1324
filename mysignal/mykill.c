#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

// kill 9 1234      //9号命令，进程1234
int main(int argc, char* argv[])
{
//	printf("%d\n",argc);	//命令行参数个数
	
	if(argc != 3)
	{
		printf("Usage: %s sig pid\n", argv[0]);   //相当于手册，说明怎么输入
		return 1; 
	}
	
	int sig = atoi(argv[1]);
	int pid = atoi(argv[2]);

	kill(pid, sig);
	//查看进程的命令   ps aux | grep 进程名	
	return 0;
}
	
