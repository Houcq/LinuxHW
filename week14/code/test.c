#include "my.h"
int i = 0;
void fun()
{
	int buffer[256] = {0};
	i = i+1;
	printf("%d\n",i);
	fun();
}
int main(){
	fun();
	return 0;
}
