#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int terminate = 0;
void handler()
{
	int exitStatus = 0;	
	
	printf("\n\t[PPID=%d]\t[PID=%d]\thandler\n",getppid(),getpid());
	
	sleep(20);

	wait(&exitStatus);
	
	if(WIFEXITED(exitStatus))
	{
		printf("\n\t[PPID=%d]\t[PID=%d]\texitValue = %d\n",getppid(),getpid(),WEXITSTATUS(exitStatus));
	}
	else if(WIFSIGNALED(exitStatus))
	{
		printf("\n\t[PPID=%d]\t[PID=%d]\tsignalValue = %d\n",getppid(),getpid(),WTERMSIG(exitStatus));
	}

	printf("\n\t[PPID=%d]\t[PID=%d]\thandler :: RECEIVED CHILD EXIT\n",getppid(),getpid());

	terminate = 1;
}

int main(int argc, char* argv[])
{
	int iPid = 0;
	
	printf("\n\t[%d]\t%s\t%s\t%s\t%s\t%d\tSTART\n",getpid(),__DATE__,__TIME__,__FILE__,__func__,__LINE__);
	
	iPid = fork();

	printf("\n\t[%d]\tiPid = %d\n",getpid(),iPid);

	if(iPid == 0)
	{
		printf("\n\t[PPID=%d]\t[PID=%d]\tCHILD\n",getppid(),getpid());
	
		printf("\n\t[PPID=%d]\t[PID=%d]\tKILL CHILD\n",getppid(),getpid());

		while(1)
		{
			sleep(1);
		}

	}
	else
	{	
		printf("\n\t[PPID=%d]\t[PID=%d]\tPARENT\n",getppid(),getpid());
		
		printf("\n\t[PPID=%d]\t[PID=%d]\tPARENT WATING FOR CHILD\n",getppid(),getpid());
		
		signal (SIGCHLD, handler);
		
		while(terminate == 0)
		{
			sleep(1);		
			sleep(1);
		}

		printf("\n\t[PPID=%d]\t[PID=%d]\tPARENT-EXITING\n",getppid(),getpid());

		sleep(10);

	}


	printf("\n\t[%d]\t%s\t%s\t%s\t%s\t%d\tEND\n",getpid(),__DATE__,__TIME__,__FILE__,__func__,__LINE__);

        exit(0);
}
