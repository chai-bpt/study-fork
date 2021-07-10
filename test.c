#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char* argv[])
{
	int iPid = 0;
	int fd = 0;
	char byte = 0;

        printf("\n\t[PPID=%d]\t[PID=%d]\tCOMMON\tSTART\n",getppid(),getpid());

	printf("\n");
	iPid = fork();
	fd = open("./datafile",0,O_RDONLY);
	if(iPid == 0)
	{
		sleep(1);
		printf("\n\t[PPID=%d]\t[PID=%d]\tCHILD\n",getppid(),getpid());
		read(fd, &byte, 1);
		printf("\n\t[PPID=%d]\t[PID=%d]\tCHILD\tbyte = %c\n",getppid(),getpid(),byte);
	}
	else
	{	
		printf("\n\t[PPID=%d]\t[PID=%d]\tPARENT\n",getppid(),getpid());
		read(fd, &byte, 1);
		printf("\n\t[PPID=%d]\t[PID=%d]\tPARENT\tbyte = %c\n",getppid(),getpid(),byte);
	}    

        printf("\n\t[PPID=%d]\t[PID=%d]\tCOMMON\tEXIT\n",getppid(),getpid());
        exit(0);
}
