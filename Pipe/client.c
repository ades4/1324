#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{
	int fd = open("fifo", O_WRONLY);      //以写方式打开文件
	if(fd < 0)
	{
		printf("open error\n");
		return 1;
	}

	char buf[1024];		
	while(1)
	{
		ssize_t s = read(0, buf, sizeof(buf)-1);		//从标准输入里读数据
		if(s > 0)
		{
			buf[s] = 0;
			write(fd, buf, strlen(buf));
		}
		else if(s == 0)  
		{
			printf("client quit!\n");
			break;
		}
		else
		{
			printf("read error!\n");
			break;
		}
	}

	close(fd);  //关闭文件
	return 0;
}
