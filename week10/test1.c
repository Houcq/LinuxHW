#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
void fun1(void)
{
	printf("invoked callbackfun");
}
int main(){
	atexit(fun1);
	FILE *fp;
	char buf[] = "buffer data!";
	if((fp = fopen("test.dat","w+")) == NULL)
	{
		perror("create file failed!\n");
		exit(-1);
	}
	if((fputs(buf,fp)) == EOF)
	{
		perror("Fputs file failed!\n");
		exit(-1);
	}
	printf("hello ");
	_exit(0);
}
