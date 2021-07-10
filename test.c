#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int func(void)
{
        printf("\n\t[PPID=%d]\t[PID=%d]\tCOMMON\tIN_FUNC\n",getppid(),getpid());
}

int main(int argc, char* argv[])
{
	int iPid = 0;

	printf("\n\t[PPID=%d]\t[PID=%d]\tPARENT\n",getppid(),getpid());
	func();

	printf("\n");
	iPid = fork();//Copy on write (COW) for iPid
	
	printf("\n\t[PPID=%d]\t[PID=%d]\tCOMMON\n",getppid(),getpid());
	func();	

	if(iPid == 0)
	{ 
		printf("\n\t[PPID=%d]\t[PID=%d]\tCHILD\n",getppid(),getpid());
		func();
	}
	else
	{	
		printf("\n\t[PPID=%d]\t[PID=%d]\tPARENT\n",getppid(),getpid());
		func();
	}    
	
	printf("\n\t[PPID=%d]\t[PID=%d]\tCOMMON\n",getppid(),getpid());
	func();	

        printf("\n\t[PPID=%d]\t[PID=%d]\tCOMMON\tEXIT\n",getppid(),getpid());
        exit(0);
}
