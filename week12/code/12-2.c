#include "my.h"
int main()
{
	int pid1,pid2,pid3;
	pid1 = fork();
	if(pid1<0)
	{
		perror("fork1 failed!\n");
		return -1;	
	}
	else if(pid1 == 0)
	{
		printf("i am chiled1!\n");
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
			printf("i am child2!\n");
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
			printf("i am child3!\n");
			exit(0);
			}
			else{
				printf("i have 3 child!\n");
				return 0;
			}		
		}
	}
}
