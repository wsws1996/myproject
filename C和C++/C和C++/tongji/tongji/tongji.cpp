// tongji.cpp : �������̨Ӧ�ó������ڵ㡣
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
	printf("��д��ĸΪ��%d��Сд��ĸΪ�� %d������Ϊ��%d�������ַ�Ϊ��%d\n",da, xiao, num, other);

	system("pause");
	return 0;
}

