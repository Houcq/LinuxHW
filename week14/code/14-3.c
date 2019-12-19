#include "my.h"
#define NUM 4
struct nums{
int i;
int k;
};
void fun(void *arg)
{
	//int *pt;
	//pt = (int *)arg;
	//printf("worker thread %d : tid = %p\n",(int)pt,pthread_self());
	struct nums * a;
	a = (struct nums *)arg;
	printf("%d,%d\n",a->i,a->k);
}
int main()
{
	pthread_t tid[NUM];
	int ret;
	int i;
	struct nums a[4];
	for(i = 0;i<NUM;i++)
	{
		a[i].i = i;
		a[i].k = i*100+100;
		pthread_create(&tid[i],NULL,(void *(*))fun,(void *)&a[i]);
	}
	for(i = 0;i<NUM;i++)
	{
		pthread_join(tid[i],NULL);
	}
	printf("ALL finished!\n");
	return 0;
}
