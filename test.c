#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int iGlobal = 90;

int main(int argc, char* argv[])
{
	int iPid = 0;
	int iLocal = 10;
	
	printf("\n\t[PPID=%d]\t[PID=%d]\tPARENT\tiGlobal = %d\n",getppid(),getpid(),iGlobal);
	printf("\n\t[PPID=%d]\t[PID=%d]\tPARENT\t&iGlobal = %p\n",getppid(),getpid(),&iGlobal);
	printf("\n\t[PPID=%d]\t[PID=%d]\tPARENT\tiLocal = %d\n",getppid(),getpid(),iLocal);
	printf("\n\t[PPID=%d]\t[PID=%d]\tPARENT\t&iLocal = %p\n",getppid(),getpid(),&iLocal);
	printf("\n");

	printf("\n");
	iPid = fork();//Copy on write (COW) for iPid

	printf("\n\t[PPID=%d]\t[PID=%d]\tCOMMON\tiPid = %d\n",getppid(),getpid(),iPid);
	iGlobal++;//COW
	iLocal++;//COW
       	printf("\n\t[PPID=%d]\t[PID=%d]\tCOMMON\tiGlobal = %d\n",getppid(),getpid(),iGlobal);
        printf("\n\t[PPID=%d]\t[PID=%d]\tCOMMON\t&iGlobal = %p\n",getppid(),getpid(),&iGlobal);
        printf("\n\t[PPID=%d]\t[PID=%d]\tCOMMON\tiLocal = %d\n",getppid(),getpid(),iLocal);
        printf("\n\t[PPID=%d]\t[PID=%d]\tCOMMON\t&iLocal = %p\n",getppid(),getpid(),&iLocal);
	printf("\n");
		

	if(iPid == 0)
	{
	       	iGlobal++;
        	iLocal++;
        	printf("\n\t[PPID=%d]\t[PID=%d]\tCHILD\tiGlobal = %d\n",getppid(),getpid(),iGlobal);
        	printf("\n\t[PPID=%d]\t[PID=%d]\tCHILD\t&iGlobal = %p\n",getppid(),getpid(),&iGlobal);
        	printf("\n\t[PPID=%d]\t[PID=%d]\tCHILD\tiLocal = %d\n",getppid(),getpid(),iLocal);
      	  	printf("\n\t[PPID=%d]\t[PID=%d]\tCHILD\t&iLocal = %p\n",getppid(),getpid(),&iLocal);
		printf("\n");
	}
	else
	{	
		iGlobal++;
                iLocal++;
                printf("\n\t[PPID=%d]\t[PID=%d]\tPARENT\tiGlobal = %d\n",getppid(),getpid(),iGlobal);
                printf("\n\t[PPID=%d]\t[PID=%d]\tPARENT\t&iGlobal = %p\n",getppid(),getpid(),&iGlobal);
                printf("\n\t[PPID=%d]\t[PID=%d]\tPARENT\tiLocal = %d\n",getppid(),getpid(),iLocal);
	        printf("\n\t[PPID=%d]\t[PID=%d]\tPARENT\t&iLocal = %p\n",getppid(),getpid(),&iLocal);
		printf("\n");
	}

        iGlobal++;
        iLocal++;
        printf("\n\t[PPID=%d]\t[PID=%d]\tCOMMON\tiGlobal = %d\n",getppid(),getpid(),iGlobal);
        printf("\n\t[PPID=%d]\t[PID=%d]\tCOMMON\t&iGlobal = %p\n",getppid(),getpid(),&iGlobal);
        printf("\n\t[PPID=%d]\t[PID=%d]\tCOMMON\tiLocal = %d\n",getppid(),getpid(),iLocal);
        printf("\n\t[PPID=%d]\t[PID=%d]\tCOMMON\t&iLocal = %p\n",getppid(),getpid(),&iLocal);
	printf("\n");
	

        printf("\n\t[PPID=%d]\t[PID=%d]\t\tEXIT\n",getppid(),getpid());
        exit(0);
}
