#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	printf("\n\t[%d]\t%s\t%s\t%s\t%s\t%d\tSTART",getpid(),__DATE__,__TIME__,__FILE__,__func__,__LINE__);
	fork();
	printf("\n\t[%d]\t%s\t%s\t%s\t%s\t%d\tEND\n",getpid(),__DATE__,__TIME__,__FILE__,__func__,__LINE__);

        exit(0);
}
