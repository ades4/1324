#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void show(sigset_t *pending)
{
	int i = 1;
	for(; i <= 31; i++)
	{	
		if(sigismember(pending, i))
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	printf("\n");
}

int main()
{ 
	//2 --->block
	//pinding-->show-->01000000...0
	sigset_t set, oset;
	sigemptyset(&set);			//sigemptyset初始化set所指向的信号集
	sigemptyset(&oset);

	sigaddset(&set, 2);			//在信号集中添加某种有效信息
	
	sigprocmask(SIG_SETMASK, &set, &oset);   //可以读取或更改进程的信号屏蔽字(阻塞信号集)

	int count = 10;
	while(1){
		sigset_t pending;
		sigemptyset(&pending);
		sigpending(&pending);		//读取当前进程的未决信号集
		show(&pending);
		sleep(1);

		if(count-- <= 0){
			printf("recover handler!\n");
			sigprocmask(SIG_SETMASK, &oset, NULL);   //解除了阻塞,实际执行信号的处理动作
		}
	}
}




//5种产生信号的方法，  键盘（只能发送给前台）    命令     系统调用（kill）   软件条件（闹钟）   硬件异常  ———>操作系统执行  —>发信号的方法：向进程写信号，修改进程位图对应的比特位  

//
//int count = 0;
//void handler(int signo)		//修改收到信号的处理动作
//{
//	printf("catch signo, signo: %d, count: %d\n", signo, count);  // 在后台运行直接由CPU计算，数值很大
//	exit(1);
//}
//
//int main()
//{
////	signal(2, handler);
//// 	signal(2, SIG_IGN);	    //忽略信号
////	signal(2, SIG_DFL);		//默认处理动作
//
//	int i = 1;
//	while(i <= 31)
//	{
//		signal(i, handler);		//专门用来捕捉的函数，第一个参数是信号编号，第二个参数类型是函数指针，收到信号的处理动作
//		i++;
//	}
//	sleep(3);
//	int a = 10;
//	a /= 0;       //除0错误
//	while(1);
//
////	signal(SIGALRM, handler); 		//自定义方法 SIGALRM 闹钟
////	alarm(1); 			//闹钟，一秒后进程退出
//
////	int count = 0;
////	while(1)
////	{
////		printf("i am process...: %d\n", count++);
////		//sleep(1);
////	}
//
//	return 0;
//}
//
