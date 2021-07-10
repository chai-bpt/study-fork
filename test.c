#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{
	int iPid = 0;

	if(0)
	{
common_code:
		printf("\n\t[PPID=%d]\t[PID=%d]\tCOMMON CODE::JUMP SUCCESS\n",getppid(),getpid());
		goto exit;
	}
	
	printf("\n");
	iPid = fork();
	if(iPid == 0)
	{ 
		printf("\n\t[PPID=%d]\t[PID=%d]\tCHILD\n",getppid(),getpid());
		goto common_code;			
	}
	else
	{	
		printf("\n\t[PPID=%d]\t[PID=%d]\tPARENT\n",getppid(),getpid());
		goto common_code;	
	}    
	
exit:
        printf("\n\t[PPID=%d]\t[PID=%d]\tCOMMON\tEXIT\n",getppid(),getpid());
        exit(0);
}
