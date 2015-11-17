// tongji.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "string.h"
#include "windows.h"
int _tmain(int argc, _TCHAR* argv[])
{
	int da = 0;
	int xiao = 0;
	int num = 0;
	int space = 0;
	int	other = 0;
	int i;
	char str[300];
	gets_s(str);
	for (i = 0; i<=strlen(str); ++i)
	{
		if (str[i] == ' ')
			space++;
		else if (str[i]<='Z'&&str[i]>='A')
			da++;
		else if (str[i] <= 'z'&&str[i] >= 'a')
			xiao++;
		else if (str[i] <= '9'&&str[i] >= '0')
			num++;
		else
			other++;
	}
	printf("大写字母为：%d，小写字母为： %d，数字为：%d，其他字符为：%d\n",da, xiao, num, other);

	system("pause");
	return 0;
}

