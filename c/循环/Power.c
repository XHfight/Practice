/*************************************************************************
	> File Name: Power.c
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Thu 05 Jan 2017 09:03:55 PM CST
 ************************************************************************/
/*题目:
 *给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。
 * */

#include <stdio.h>
#include <math.h>

//注意： 指数可能为负数
double Power(double base, int exponent)
{
	double ret = 1.0;
	int exp = abs(exponent);
	int i = 0;
	for(i = 0; i < exp; ++i)
	{
		ret *= base;
	}

	if(exponent >= 0)
		return ret;
	else
		return 1/ret;
}
int main()
{
	printf("1.0, 2:%lf\n", Power(1.0, 2));
	printf("2.0, -2:%lf\n", Power(2.0, -2));
	return 0;
}
