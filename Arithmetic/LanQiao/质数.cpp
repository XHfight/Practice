/*************************************************************************
	> File Name: 质数.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Wed 26 Apr 2017 08:19:48 PM CST
 ************************************************************************/

/*
问题描述
　　输出1~100间的质数并显示出来。注意1不是质数。
输出格式
　　每行输出一个质数。
　　2
　　3
　　...
　　97
*/


#include<iostream>
#include<cmath>
using namespace std;

//1.注意：1和偶数（2除外）都不是质数，2是质数
//2.只能被1和他本身整除的是质数 [0, sqrt(num)]
bool IsPrime(int num)
{
	if(num == 1)
		return false;
	if(num == 2)
		return true;
	if(num%2 == 0)
		return false;
	for(int i = 2; i <= sqrt(num); ++i)
	{
		if(num % i == 0)
			return false;
	}
	return true;
}

int main()
{
	for(int i = 1; i <= 100; ++i)
	{
		if(IsPrime(i))
			cout << i << endl;
	}
	return 0;
}
