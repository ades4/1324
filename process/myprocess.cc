#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
using namespace std;

int main()
{
	pid_t id = fork();
//	cout << "id: " << id << endl;
	if(id == -1){
		cerr << "fork error " << endl;
	}
	int count = 0;
	if(id == 0){//chlid
		while(1){
			cout << "I am chlid ..." << endl;
//			count++;
			sleep(1);
//			if(count >= 3)
//				exit(1);   //退出进程
		}
	}
	else
	{
		while(1){//father
			cout << "I am father " << endl;
			sleep(1);
			if(count++ >= 3)
				exit(1);
		}
	}

	//printf("process : %d, parent: %d\n", getpid(), getppid());
	//sleep(1);
	return 0;
}

