#include "my.h"
#define NUM 4
struct nums{
int count;
struct nums * point;
};
void fun(void *arg)
{
	//int *pt;
	//pt = (int *)arg;
	//printf("worker thread %d : tid = %p\n",(int)pt,pthread_self());
	struct nums * a;
	a = (struct nums *)arg;
	a->count++;
	a->point = &a;
	printf("%d\n",a->count);
	pthread_exit((void *)&a->count);
}
int main()
{
	pthread_t tid[NUM];
	void* ret[NUM];
	int i;
	struct nums a[4];
	for(i = 0;i<NUM;i++)
	{
		a[i].count= (i+1)*100;
		a[i].point = NULL;
		pthread_create(&tid[i],NULL,(void *(*))fun,(void *)&a[i]);
	}
	for(i = 0;i<NUM;i++)
	{
		pthread_join(tid[i],ret[i]);
		printf("%d\n",*(int *)ret[i]);
	}
	printf("ALL finished!\n");
	return 0;
}
