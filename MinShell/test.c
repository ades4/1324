#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
//int main()
//{
//	//execl("usr/bin/ls","ls","-a","-l","-i",NULL);
//	//程序替换函数  ---- 替换ls命令
//	
//	//execlp("top","top",NULL);
// 	//带p不需要带路径
//
//   char *argv[]={
//	   "ls",
//		"-a",
//		"-l",
//		"-i",
//		NULL
//	};
//	execv("usr/bin/ls",argv);
//	//execvp("ls",argv);
//	return 0;
//}


int main()
{
	pid_t id = fork(); //创建子进程
	if(id == 0)
	{
		execl("/home/xuman/Code/MinShell/testproc","testproc",NULL);
		exit(1);
	}
	else
	{
		waitpid(id, NULL, 0);
		printf("Waiting end...\n");
	}
}
