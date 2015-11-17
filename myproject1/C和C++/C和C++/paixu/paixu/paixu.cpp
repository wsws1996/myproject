// paixu.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include<windows.h>
#include"string.h"


int _tmain(int argc, _TCHAR* argv[])
{
	printf("请输入十个整数：");
	int a[10], i, j, x;
	for (i = 0; i < 10; ++i)
	{
		scanf_s("%d",&a[i]);
	}
	for (i = 0; i < 9; ++i)
	{
		for (j = i; j < 9; ++j)
		{
			if (a[i] > a[j + 1])
			{
				x = a[i];
				a[i] = a[j + 1];
				a[j + 1] = x;
			}
		}
	}
	printf("这些整数从小到大依次排序为：\n");
	for (i = 0; i < 10; ++i)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	printf("press any key to contine\n");
	printf("\n");
	system("pause");
	return 0;
}

