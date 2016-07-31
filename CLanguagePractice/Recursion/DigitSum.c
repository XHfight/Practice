#include <stdio.h>

/*
题目：写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和。
例如，调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19。
*/
int DigitNum(int num)
{
	int sum = 0;
	if(num/10 == 0)  //num只有一位的情况
	{
		sum = num;
		return sum;
	}
	else
	{
		sum = (num%10) + DigitNum(num/10);
	}

	return sum;
}

int main()
{ 

	int ret = DigitNum(1729);
	printf("%d\n", ret);
	return 0;
}
