#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	int pid,s;
	if((pid = fork())<0)
	{
		perror("failes	to fork!\n");
		return -1;	
	}
	else if(pid == 0)
	{
		printf("%d:child is running now!\n",getpid());
		while(1);
		printf("%d:child exit now.\n",getpid());
		exit(120);
	}
	else {
		printf("%d:parent is running\n",getpid());
		while((pid = wait(&s))!=-1)
		{
			if(WIFEXITED(s))
			{
				printf("child %d is exiting normally exit code = %d\n",pid,WEXITSTATUS(s));
			}
			else if(WIFSIGNALED(s))
			{
				printf("child %d exit by signal signal no  = %d\n",pid,WTERMSIG(s));			
			}
			else{
				printf("not knnow!\n");			
			}
		}
		printf("%dparent is exiting now\n",getpid());
	}
	exit(0);
}
