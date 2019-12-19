#include "my.h"
int main()
{
	pid_t r;
	int r_num = 0;
	int pipefd[2];
	if(pipe(pipefd)<0)
	{

		perror("pipe failed.\n");
		return -1;
	}

	r = fork();
	if(r<0)
	{
		perror("fork failed!\n");
		return -1;
	}

	else if(r==0)
	{
		close(pipefd[0]);
		while(1){
		r_num++;
		if(write(pipefd[1],"c",1)!=-1)
			printf("%d!\n",r_num);
		}
		
		close(pipefd[1]);
		exit(0);
	}
	else{
		sleep(1000);
		exit(0);
	}
}
