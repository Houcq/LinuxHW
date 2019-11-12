#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
int g = 88;
int main()
{
	int v = 99;
	pid_t pid;
	pid = vfork();
	if(pid<0)
	{
		perror("fork failed!\n");	
 	}
	else if(pid == 0&&g == 89)
	{
		
		printf("child:pid = %d,g = %d;v = %d\n",getpid(),g,v);
		exit(0);
	}
	else if(pid>0){
		g++;
		printf("pid value = %d\n",pid);
		printf("parent pid = %d,g = %d,v = %d\n",getppid(),g,v);
		exit(0);
	}
	
}
