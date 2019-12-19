#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	int pid1,pid2,s,j;
	pid1 = fork();
	pid2 = fork();
	if((pid1 <0)&& (pid2<0))
	{
		perror("fork filled !");
		return -1;	
	}
	else if(pid1 ==0)
	{
		printf("I am child1,pid = %d\n",getpid());
		while(1)
		exit(120);
	}
	else if(pid2 == 0)
	{
		printf("I am child2,pid = %d\n",getpid());
		while(1);
		exit(130);
	}
	else
	{
		printf("我是爸爸%d我来回收你们了！\n",getpid());
		while((j = wait(&s)) != -1)
		{
			if(WIFEXITED(s))
			{
				printf("child is exiting normally exit code = %d\n",WEXITSTATUS(s));
			}
		}
	}
	/*if((pid = fork())<0)
	{
		perror("failes	to fork!\n");
		return -1;	
	}
	else if(pid == 0)
	{
		sleep(10);
		printf("%d:child is running now!\n",getpid());
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
	}*/
	exit(0);
}
