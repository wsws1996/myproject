# include <stdio.h>
# include <stdlib.h>

struct Arr
{
	int * pBase;
	int len;
	int cnt;	
} ;

void init_arr(struct Arr * pArr, int length);
bool append_arr(struct Arr * pArr, int val);//追加 
bool insert_arr(struct Arr * pArr, int pos, int val);//插入 
bool delete_arr(struct Arr * pArr, int pos,int *pval);//删除 
int get();
bool is_empty(struct Arr * pArr);
bool is_full(struct Arr * pArr);
void sort_arr(struct Arr * pArr);
void show_arr(struct Arr * pArr);
void inversion_arr(struct Arr * pArr); 

int main (void) 
{
	struct Arr arr;
	int val;
	
	init_arr(&arr,6);
	append_arr(&arr,1);
	append_arr(&arr,2);
	append_arr(&arr,3);
	append_arr(&arr,4);
	append_arr(&arr,5);
	show_arr(&arr);
	insert_arr(&arr,2,0);
	show_arr(&arr);
	if(	delete_arr(&arr,2,&val))
		printf("删除成功！\n您删除的元素是：%d\n",val);
	else
		printf("删除失败！\n");
	show_arr(&arr);
	inversion_arr(&arr);
	show_arr(&arr);
	insert_arr(&arr,2,0);
	show_arr(&arr);
	sort_arr(&arr);
	show_arr(&arr);
	return 0;
} 

void init_arr(struct Arr * pArr,int length)
{
	pArr->pBase = (int *)malloc(sizeof(int)*length);
	if(NULL==pArr->pBase)
	{
		printf("动态内存分配失败，程序即将退出！\n");
		exit(-1);
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}
	return;
}

void show_arr(struct Arr * pArr)
{
	if(is_empty(pArr))
		printf("数组为空，无需输出！\n");
	else
	{
		int i;
		for(i=0;i<(pArr->cnt);++i)
			printf("%d ",pArr->pBase[i]);
		printf("\n");
	}
}

bool is_empty(struct Arr * pArr)
{
	if(pArr->cnt==0)
		return true;
	else
		return false;
}

bool is_full(struct Arr * pArr) 
{
	if(pArr->cnt==pArr->len)
		return true;
	else
		return false;
}

bool append_arr(struct Arr * pArr,int val)
{
	if(is_full(pArr))
		return false;
	else
	{
		pArr->pBase[pArr->cnt]=val;
		(pArr->cnt)++;
	}
	return true;
}

bool insert_arr(struct Arr * pArr, int pos, int val)
{
	if(is_full(pArr)||pos<1||pos>=pArr->len+1)
		return false;
	else
	{
		int i;
		for(i=pArr->cnt-1;i>=pos-1;--i)
			pArr->pBase[i+1] = pArr->pBase[i];
		pArr->pBase[pos-1]=val;
		pArr->cnt++;
		return true;
	}
	return true;
}

bool delete_arr(struct Arr * pArr, int pos,int *pVal)
{
	if(is_empty(pArr)||pos<1||pos>(pArr->cnt))
		return false;
	else
	{
		*pVal=pArr->pBase[pos-1];
		int i;
		for(i=pos;i<=pArr->cnt;++i)
			{
				pArr->pBase[i-1]=pArr->pBase[i];
			}
			pArr->cnt--;
			return true;
	}
}

void inversion_arr(struct Arr * pArr)
{
	int i=0,t=0,j=pArr->cnt-1;
	while(i<j)
	{
		t=pArr->pBase[i];
		pArr->pBase[i]=pArr->pBase[j];
		pArr->pBase[j]=t;
		i++;
		j--;
	}
	return;
}

void sort_arr(struct Arr * pArr)
{
	int i,j,t;
	for(i=0;i<pArr->cnt;++i)
	{
		for(j=i+1;j<pArr->cnt;++j)
		{
			if(pArr->pBase[i]>pArr->pBase[j])
			{
				t=pArr->pBase[i];
				pArr->pBase[i]=pArr->pBase[j];
				pArr->pBase[j]=t;
			}
		}
	}
}
