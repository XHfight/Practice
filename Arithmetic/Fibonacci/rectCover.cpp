/*************************************************************************
	> File Name: rectCover.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Wed 31 May 2017 08:12:34 PM CST
 ************************************************************************/

/*
 *我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
 *请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 */
#include<iostream>
using namespace std;

/*思路：覆盖2*n的矩阵
 * 1.当n<=0, return 1
 * 2.当n==1, return 1
 * 3.当n==2, return 2
 * 4.当n>2
 *   如果第一个放置2*1，则剩余为f(n-1)
 *   如果第一个放置1*2，则剩余为f(n-2)
 */
int rectCover(int number)
{
	if(number <= 0)
		return 0;
	else if(number == 1)
		return 1;
	else if(number == 2)
		return 2;
	else
		return rectCover(number-1)+rectCover(number-2);
}

int main()
{
	int num = 5;
	cout << rectCover(num) << endl;
	return 0;
}
