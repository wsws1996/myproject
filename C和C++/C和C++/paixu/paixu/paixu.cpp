// paixu.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<stdio.h>
#include<windows.h>
#include"string.h"


int _tmain(int argc, _TCHAR* argv[])
{
	printf("������ʮ��������");
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
	printf("��Щ������С������������Ϊ��\n");
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

