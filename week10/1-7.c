#include "my.h"
int main()
{
	static int a = 0;
	pid_t pid;
	pid = vfork();
	if(pid <0)
	{
		perror("vfork faile\n");
		exit(0);
	}
	else if(pid == 0)
	{
		while(a == 0)
		{
			printf("等待\n");
		}		
		printf("儿子成功了！\n");
		exit(0);
		
	}
	else{
		a = 1;
		printf("父亲开始了！\n");
		return 0;
	}
}
