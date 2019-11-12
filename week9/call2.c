#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	char* argv[] = {"./test","Hello","boy",NULL};
	printf("call2 Pid = %d,  PPID = %d\n",getpid(),getppid());
	execve("./test",argv,NULL);
	printf("after\n");
	return 0;
}
