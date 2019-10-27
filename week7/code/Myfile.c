#include "Myfile.h"
#include <stdio.h>
#include <stdlib.h>
void NewFile()
{
	FILE *fp1;
	int i;
	char *a= "test.txt";
	fp1 = fopen(a,"w+");
	if(fp1 == NULL)
	{
		perror("创建文件失败\n");
		exit(0);
	}
	printf("创建文件成功\n");
	for(i = 0;i < 4;i++)
	{
		printf("\n");
	}
	fclose(fp1);
}

void WriteFile()
{
	FILE *fp1;
	int i,boo;
	char *a= "test.txt";
	char b[100];
	fp1 = fopen(a,"w");
	if(fp1 == NULL)
	{
		perror("打开文件失败\n");
		exit(0);
	}
	printf("请输入你想要写入的内容：\n");
	scanf("%s",b);
	boo = fputs(b,fp1);
	printf("%s",b);
	if(boo != -1)
	{
		printf("输入成功\n");
	}
	for(i = 0;i < 4;i++)
	{
		printf("\n");
	}
	fclose(fp1);
}
void ReadFile()
{
	FILE *fp1;
	int i,boo;
	char ch;//用于存储文件中的信息
	char *a= "test.txt";
	fp1 = fopen(a,"r");
	if(fp1 == NULL)
	{
		perror("打开文件失败\n");
		exit(0);
	}
	printf("文件内容为：\n");
	//读取字符到屏幕上的操作
	ch = fgetc(fp1);
	while(ch!=EOF)
	{
		putchar(ch);
		ch=fgetc(fp1);
	}

	printf("读取完毕\n");
	for(i = 0;i < 4;i++)
	{
		printf("\n");
	}
	fclose(fp1);
}
void ChangeFileRoot()
{
	int ret,i;
	ret = chmod("test.txt", 0777);
    if(ret)
    {
        printf("\nplease make sure the file path!\n");
    }
	printf("修改成功！\n");
	for(i = 0;i < 4;i++)
	{
		printf("\n");
	}
}
void AboutFileRoot(){
	int acc,ret,i;
	printf("该文件权限为：");
	if(access("test.txt",R_OK))
	{
		printf("不可读");
	}
	else
	printf("可读");
	if(access("test.txt",W_OK))
	{
		printf("不可写");
	}
	else
	printf("可写");
	if(access("test.txt",X_OK))
	{
		printf("不可执行\n\n");
	}
	else
	printf("可执行\n\n");
	printf("请输入修改后的权限值：");
	scanf("%4o",&acc);
	ret = chmod("test.txt", acc);
    if(ret)
    {
        printf("\nplease make sure the file path!\n");
    }
	printf("修改成功！\n");
	for(i = 0;i < 4;i++)
	{
		printf("\n");
	}
}
void Main(){
int i;
	while(1){
		printf("*************************************\n");
		printf("0.退出\n");
		printf("1.创建新文件\n");
		printf("2.写文件\n");
		printf("3.读文件\n");
		printf("4.修改文件权限\n");
		printf("5.查看当前文件权限修改文件权限\n");
 		printf("*************************************\n");
		printf("请输入你的选择（0-6）：");
		scanf("%d",&i);
		switch(i)
		{
			case 0:
				exit(0);
			break;
			case 1:
				NewFile();
			break;
			case 2:
				WriteFile();
			break;
			case 3:
				ReadFile();
			break;
			case 4:
				ChangeFileRoot();
			break;
			case 5:
				AboutFileRoot();
			break;
		}
	}
}
