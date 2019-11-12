#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	printf("call Pid = %d,  PPID = %d\n",getpid(),getppid());
	system("./test");
	printf("after\n");
	return 0;
}
