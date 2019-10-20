#include "dylib.h"
#include <stdio.h>
int main()
{
	int a[5] = {12,4,5,6,99};
	show(a,5);
	printf("最大值为：%d\n",max(a,5));
	printf("和为：%d\n",sum(a,5));
}
