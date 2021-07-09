#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	int iPid = 0;
	
	printf("\n\t[%d]\t%s\t%s\t%s\t%s\t%d\tSTART\n",getpid(),__DATE__,__TIME__,__FILE__,__func__,__LINE__);
	
	iPid = fork();

	printf("\n\t[%d]\tiPid = %d\n",getpid(),iPid);

	if(iPid == 0)
	{
		printf("\n\t[PPID=%d]\t[PID=%d]\tCHIELD\n",getppid(),getpid());
		
		while(1)
		{
			sleep(10);
		}

	}
	else
	{
		printf("\n\t[PPID=%d]\t[PID=%d]\tPARENT\n",getppid(),getpid());
		
		sleep(20);

		printf("\n\t[PPID=%d]\t[PID=%d]\tPARENT-EXITING\n",getppid(),getpid());

	}


	printf("\n\t[%d]\t%s\t%s\t%s\t%s\t%d\tEND\n",getpid(),__DATE__,__TIME__,__FILE__,__func__,__LINE__);

        exit(0);
}
