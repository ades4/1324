#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int i = 0;
	char bar[52];
	memset(bar, 0, sizeof(bar));
	const char *lable = "-/|\\";
	while(i <= 50)
	{	
		printf("[%-50s][%d%%][%c]\r", bar, i*2, lable[i%4]);
		bar[i++] = '#';
		usleep(10000);

		fflush(stdout); 
	}
	printf("\n");
	return 0;
}


