#include"stdafx.h"
#include<stdio.h>
#include<math.h>
int main()
{
	int m, n, i, s2;
	double R[20] = {0}, s1, max;
	scanf_s("%d", &m);
	getchar();
	scanf_s("%d", &n);
	getchar();
	for (i = 0; i < m; i++)
	{
		for (i = 0; i<n; i++) 
			scanf_s("%d", &R[i]);
		getchar();
		max = R[0];
		for (i = 0; i<n; i++)
		{
			max = (max>R[i + 1]) ? max : R[i + 1];
		}
		s1 = 10 / sqrt(max*max - 1);
		s2 = (int)s1;
		if (s1 - s2>0)s2 = s2 + 1;
		printf("%d\n", s2);
		printf("%f\n", max);
		printf("%f\n", s1);
	}
	printf("\n");
	return 0;
}