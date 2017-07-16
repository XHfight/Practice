/*************************************************************************
	> File Name: Add.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 日  7/16 08:52:03 2017
 ************************************************************************/

//实现一个Add函数，让两个数相加，但是不能使用+、-、*、/等四则运算符。ps:也不能用++、—等等
#include<iostream>
using namespace std;
/*
用为运算解决：
1)不考虑进位，让两数相加，1,1->0   1,0->1  0,0->0 相同为0相异为1，用异或 
2)进位，1,1产生进位，与运算；之后左移一位。
3）重复前两位，直到没有进位产生。
*/

int Add(int a, int b)
{
	int sum = a^b;
	int carryBit = (a & b) << 1;
	while(carryBit)
	{
		sum = carryBit ^ sum;
		carryBit = (sum & carryBit) << 1;
	}
	return sum;
}

int main()
{

	int sum = Add(40, 20);
	cout << sum << endl;
	return 0;
}
