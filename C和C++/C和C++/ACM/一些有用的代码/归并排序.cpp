#include<iostream>
using namespace std;
#define MAXSIZE 10
void merging(int *list1,int list1_size,int *list2,int list2_size)
{
	int i=0, j=0, k=0, m=0;
	int temp[MAXSIZE];
	while (i<list1_size&&j<list2_size)
	{
		if (list1[i]<list2[j])
		{
			temp[k++] = list1[i++];
		}
		else
		{
			temp[k++] = list2[j++];
		}
	}
	while (i<list1_size)
	{
		temp[k++] = list1[i++];
	}
	while (j<list2_size)
	{
		temp[k++] = list2[j++];
	}
	for (m = 0; m<(list1_size + list2_size); ++m)
	{
		list1[m] = temp[m];
	}
}
void sort(int k[], int n)
{/*
	if (n>1)
	{
		int *list1 = k;
		int list1_size = n / 2;
		int *list2 = k + n / 2;
		int list2_size = n - list1_size;
		sort(list1, list1_size);
		sort(list2, list2_size);
		merging(list1, list1_size, list2, list2_size);
	}*/
	int i, left_min,left_max,right_min, right_max;
	int next;
	int *temp = (int *)malloc(n*sizeof(int));
	for (i = 1; i < n; i *= 2)
	{
		for (left_min = 0; left_min < n - i; left_min = right_max)
		{
			right_min = left_max = left_min + i;
			right_max = left_max + i;

			if (right_max > n)
			{
				right_max = n;
			}
			next = 0;
			while (left_min < left_max&&right_min < right_max)
			{
				if (k[left_min] < k[right_min])
				{
					temp[next++] = k[left_min++];
				}
				else
				{
					temp[next++] = k[right_min++];
				}
			}
			while (left_min<left_max)
			{
				k[--right_min] = k[--left_max];
			}
			while (next>0)
			{
				k[--right_min] = temp[--next];
			}
		}
	}
}
int main()
{
	int a[8] = { 5, 2, 9, 1, 4, 7, 8, 3};
	sort(a, 8);
	for (int i = 0; i < 8; ++i)
	{
		cout << a[i] << endl;
	}
}