#include<iostream>
#include<time.h>
using namespace std;

#define MAX_LENGTH_INSERT_SORT 7

void insertsort(int k[], int n)
{
	int i, j, temp;
	for (i = 1; i < n; i++)
	{
		if (k[i] < k[i - 1])
		{
			temp = k[i];
			for (j = i - 1; k[j]>temp; j--)
			{
				k[j + 1] = k[j];
			}
			k[j + 1] = temp;
		}
	}
}

void InsertSort(int k[], int low, int high)
{
	insertsort(k + low, high - low + 1);
}

inline void Swap(int k[], int low, int high)
{
	int temp;
	temp = k[low];
	k[low] = k[high];
	k[high] = temp;
}

int Partition(int k[], int low, int high)
{
	int point;
	int m = low + (high - low) / 2;
	if (k[low] > k[high])
		Swap(k, low, high);
	if (k[m] > k[high])
		Swap(k, m, high);
	if (k[m] > k[low])
		Swap(k, m, low);
	point = k[low];
	while (low<high)
	{
		while (low < high&&k[high] >= point)
		{
			high--;
		}
		k[low] = k[high];
		while (low<high&&k[low]<=point)
		{
			low++;
		}
		k[high] = k[low];
	}
	k[low] = point;
	return low;
}

void Qsort(int k[], int low, int high)
{
	int point;
	if (high - low > MAX_LENGTH_INSERT_SORT)
	{
		while (low < high)
		{
			point = Partition(k, low, high);
			if (point - low < high - point)
			{
				Qsort(k, low, point - 1);
				low = point + 1;
			}
			else
			{
				Qsort(k, point + 1, high);
				high = point - 1;
			}
		}
	}
	else
	{
		if (high < low)
			return;
		InsertSort(k, low, high);
	}
}

void sort(int k[],int n)
{
	Qsort(k, 0, n - 1);
}
int main()
{
	int a[8] = { 10, 2, 9, 5, 4, 7, 8, 3};
	long beg = clock();
	sort(a, 8);
	long end = clock();
	cout << (end - beg) << "ºÁÃë" << endl;
	for (int i = 0; i < 8; ++i)
	{
		cout << a[i] << endl;
	}
}