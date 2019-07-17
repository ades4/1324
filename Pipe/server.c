#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	mkfifo("fifo", 0644);			//第一个参数为创建的文件，在当前目录下，文件名为fifo， 第二个参数为文件权限
	int fd = open("fifo", O_RDONLY);      //以只读方式打开文件
	if(fd < 0)
	{
		printf("open error\n");
		return 1;
	}

	char buf[1024];		
	while(1)
	{
		ssize_t s = read(fd, buf, sizeof(buf)-1);
		if(s > 0)
		{
			buf[s] = 0;
			printf("%s",buf);
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
