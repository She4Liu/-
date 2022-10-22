#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
// 导入头文件来实现函数的声明，从而不必将每个函数都写在main函数前
#include"head.h"

// 在main.c中写主函数部分
int main()
{
	srand((unsigned int)time(NULL));
	while (1)
	{
		menu();
		printf("请输入指令： ");
		int action;
		scanf("%d", &action);
		switch (action)
		{
		case 1:
			game();
			printf("游戏结束！\n\n\n");
			break;
		case 0:
			goto exit;
		default:
			printf("指令输入错误，请重新输入！\n");
		}
	}
exit:
	return 0;
}

void menu()
{
	printf("************************************\n");
	printf("**************1. start *************\n");
	printf("**************0. exit  *************\n");
	printf("************************************\n");
}
