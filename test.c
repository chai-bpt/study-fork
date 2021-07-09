#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	printf("\n\t%s\t%s\t%s\t%s\t%d\tSTART\t[%d]",__DATE__,__TIME__,__FILE__,__func__,__LINE__,getpid());
	fork();
	printf("\n\t%s\t%s\t%s\t%s\t%d\tEND\t[%d]\n",__DATE__,__TIME__,__FILE__,__func__,__LINE__,getpid());

        exit(0);
}
