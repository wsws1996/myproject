# include "stdafx.h"
# include "iostream"
# include "string"
# include "cassert"
# include "exception"

using namespace std;

class personal :public exception
{
public:
	string name()
	{
		return "my own exception";
	}
};

unsigned long returnFactorial(unsigned short num)
{
	unsigned long sum = 1;
	unsigned long max = ULONG_MAX;
	for (int i = 1; i <= num; ++i)
	{
		sum *= i;
		max /= i;
	}
	if (max < 1)
	{
		throw personal();
	}
	else
		return sum;
}