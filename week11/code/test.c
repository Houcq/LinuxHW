#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	int child1,child2,s,i;
	char buf1[] = {"1:123456"}
	char buf2[] = {"2:123456"}
	char *pout;
	FILE *fp;
	if((fp = fopen("test.dat","w+")) == NULL)
	{
		perror("failed to open!\n");
		return -1;
	}
	if((child1 = fork())<0&&(child2 = fork())<0)
	{
		perror("failed to fork!\n");
		return -2;
	}
	else if(child1 == 0)
	{
		if(fputs(buf1,fp) == EOF)
		{
			perror("failed to fputs!\n");
			_exit(1);	
		}
		_exit(120);
	}
	else if(child2 == 0)
	{
		if(fputs(buf2,fp) == EOF)
		{
			perror("failed to fputs!\n");
			_exit(1);	
		}
		_exit(121);
	}
	else{
		while((i = waits(&s)) != -1)
		{
			printf("有一个孩子退出了，退出码为：%d\n",WEXITSTATUS(S));
		}
	}
}
