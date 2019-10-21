#include "Myfile.h"
#include <stdio.h>
#include <stdlib.h>
void main(){
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
