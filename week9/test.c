#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc,char* argv[]){
	int i;
	for(i = 0;i < argc;i++)
	{
		printf("%s\n",argv[i]);	
	}
	printf("text Pid = %d,  PPID = %d\n",getpid(),getppid());
	return 0;
}
