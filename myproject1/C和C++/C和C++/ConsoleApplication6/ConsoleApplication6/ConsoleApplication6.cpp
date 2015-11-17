// ConsoleApplication6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "windows.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int a, b, c, d, e, f, g, h, i, j, k, l;
	for (i = 10000; i < 100000; ++i)
	{
		a = i % 10;//ge
		b = i / 10;//t
		c = b % 10;//shi
		d = b / 10;//t
		e = d % 10;//bai
		f = d / 10;//t
		g = f % 10;//qian
		h = f / 10;//t
		k = i / 10000;//wan
		l = a * 10000 + c * 1000 + e * 100 + g * 10 + k;//nixu
		for (j = 1; j < 10; ++j)
		{
			if (i*j == l)
			{
				printf("%d*%d=%d\n",i,j,l);
			}
		}
	}
	system("pause");
	return 0;
}

