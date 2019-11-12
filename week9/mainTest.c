#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
static void __attribute__ ((constructor)) before_main()
{
	printf("Running before main!\n");
}
static void callback1()
{
	printf("1:Running after main!");
}
static void callback2()
{
	printf("2:Running after main!");
}
static void callback3()
{
	printf("3:Running after main!");
}
int main()
{
	atexit(callback1);
	atexit(callback2);
	atexit(callback3);
	printf("test1:pid = %d,ppid = %d\n",getpid(),getppid());
	sleep(2);
}