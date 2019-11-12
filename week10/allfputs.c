#include "my.h"
int main()
{
	pid_t pid;
	char buffer1[] = "13579";
	char buffer2[] = "24680";
	FILE *fp;
	if((fp = fopen("test.dat","w++")) == NULL)
	{
		perror("内存错误！\n");
		exit(-1);
	}
	pid = vfork();
	if(pid < 0)
	{
		perror("fork faill!\n");
		exit(-1);
	}
	else if(pid == 0)
	{
		if(fputs(buffer1,fp) == EOF)
		{
			printf("子进程打印失败！\n");
			exit(-2);
		}
		_exit(0);
	}
	else{
		if(fputs(buffer2,fp) == EOF)
		{
			printf("父进程打印失败！\n");
			exit(-3);
		}
		return 0;
}

}
