#include "my.h"
int main()
{
	int pid1,pid2,pid3;
	int pipefd1[2];
	int pipefd2[2];
	char buff1[10];
	char buff2[10];
	int num1,num2;
	if(pipe(pipefd1)<0)
	{
		perror("pipe1 failed!\n");
		return -1;
	}
	if(pipe(pipefd2)<0)
	{
		perror("pipe2 failed!\n");
		return -1;
	}
	pid1 = fork();
	if(pid1<0)
	{
		perror("fork1 failed!\n");
		return -1;	
	}
	else if(pid1 == 0)
	{
		printf("i am chiled1 pid = %d,ppid = %d!\n",getpid(),getppid());
		close(pipefd1[0]);
		if(write(pipefd1[1],"0123456789",10)!=-1)
		{
			printf("child1 write ok!\n");
		}
		close(pipefd1[1]);
		exit(0);
	}
	else{
		pid2 = fork();
		if(pid2<0)
		{
			perror("fork2 failed!\n");
			return -1;	
		}
		else if(pid2 == 0)
		{
			printf("i am child2!pid = %d,ppid = %d\n",getpid(),getppid());
			close(pipefd1[1]);
			if((num1 = read(pipefd1[0],buff1,10))>0)
			{
				printf("read from pipe1:%s\n",buff1);
			}
			close(pipefd1[0]);
			close(pipefd2[0]);
			if(write(pipefd2[1],buff1,10)!=-1)
			{
				printf("child2 write ok!\n");
			}
			close(pipefd2[1]);
			exit(0);
		}
		else{
			pid3 = fork();
			if(pid3<0)
			{
			perror("fork3 failed!\n");
			return -1;	
			}
			else if(pid3 == 0)
			{
			printf("i am child3!pid = %d,ppid = %d\n",getpid(),getppid());
			close(pipefd2[1]);
			if((num2 = read(pipefd2[0],buff2,10))>0)
			{
				printf("child3 read from pipe2:%s\n",buff2);
			}
			close(pipefd2[0]);
			exit(0);
			close(pipefd2[0]);
			}
			else{
				sleep(10);
				printf("i have 3 child!\n");
				return 0;
			}		
		}
	}
}
