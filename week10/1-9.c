#include "my.h"
int main()
{
	int a = 1;
	int g = 1;
	int k = 1;
	pid_t pid;
	pid = vfork();
	if(pid<0)
	{
		perror("fork发生错误！\n");	
		exit(0);
	}
	else if(pid == 0)
	{
		printf("孩子开始了\n");
		execl("./test",test);
		printf("孩子结束了！\n");
		_exit(12);
	}
	else{
		wait(&s);
		printf(“父母开始了！孩子退出号码为：%d\n”,WEXITSTATUS(s));
		return 0;
	}
}
