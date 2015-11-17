// yanghuisanjiao.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<windows.h>


int _tmain(int argc, _TCHAR* argv[])
{
	int i, j;
	int a[10][10] = { 0 };
	for (i = 0; i < 10; ++i);
	{
		a[i][0] = 1;
	}
	for (i = 1; i < 10; ++i)
	{
		for (j = 1; j < i + 1; ++j)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (i = 0; i < 10; ++i)
	{
		for (j = 0; j < i + 1; ++j)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

