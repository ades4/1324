#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define NUM 32
using namespace std;

int main()
{
	char buff[1024] = { 0 };
	string tips = "[XM@localhost YYY]$ ";
	cout << tips;
	//while(cin>>command)
	//{ }   
	fgets(buff, sizeof(buff) - 1, stdin); 
	buff[strlen(buff) - 1] = 0;  //把输入之后的回车位，设置为0
	
	//传入 ls -a -l -o
	char *argv[NUM];
	argv[0] = strtok(buff," "); //提取字符
	int i = 0;
	while(argv[i] != NULL)
	{	
		i++;
		argv[i] = strtok(NULL, " ");  //首次调用时，第一个参数为需分解的字符串，第二次调用第一个参数为NULL
		//此时argv[0]放的为ls的首地址，argv[1] 为-a首地址 … argv[4]为空
	}
	pid_t id = fork();
	if(id == 0)
	{
		//child
		execvp(argv[0], argv);
		exit(3);
	}
	else
	{
		int status = 0;  //子进程的退出状态
		waitpid(id, &status, 0);
		cout << "Exit Code: " << WEXITSTATUS(status) << endl; //查看进程退出码
	}	

	return 0;
}
