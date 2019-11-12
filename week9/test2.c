#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
int a = 1;
int b;
int main(){
	int c = 3;
	static int d = 4;
	pid_t pid = fork();
	if(pid<0)
	{
		perror("创建进程失败.\n");
		exit(-1);	
	}
	else if(pid == 0)
	{
		printf("Child pid = %d,ppid = %d\n",getpid(),getppid());
		a = 100;
		b = 100;
		c = 100;
		d = 100;
		exit(0);
	}
	else{
		printf("Parent pid = %d,ppid = %d\n",getpid(),getppid());
		//sleep(10);
		//printf("%d,%d,%d,%d\n",a,b,c,d);
		exit(0);
	}
}
