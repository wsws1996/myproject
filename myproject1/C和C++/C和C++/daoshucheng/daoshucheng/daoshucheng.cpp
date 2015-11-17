// ConsoleApplication6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "windows.h"
#include <stdio.h>
#include <cstl/cvector.h>

int main(int argc, char* argv[])
{
	vector_t* pt_vec = create_vector(int);
	size_t t_index = 0;
	if (pt_vec == NULL)
	{
		return -1;
	}

	vector_init(pt_vec);

	for (t_index = 0; t_index < 10; ++t_index)
	{
		vector_push_back(pt_vec, t_index * 100);
	}
	for (t_index = 0; t_index < vector_size(pt_vec); ++t_index)
	{
		printf("%d, ", *(int*)vector_at(pt_vec, t_index));
	}
	printf("\n");

	vector_destroy(pt_vec);

	return 0;
}