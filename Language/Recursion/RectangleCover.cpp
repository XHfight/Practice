/*************************************************************************
	> File Name: RectangleCover.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Thu 05 Jan 2017 07:04:43 PM CST
 ************************************************************************/

/*题目：
 *我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 * */
#include<iostream>
using namespace std;

int RectCover(int number)
{
	int method[100];
	method[0] = 1;
	method[1] = 1;
	if(number <= 0)
		return 0;
	else if(number == 1)
		return 1;
	else
	{
		for(int i = 2; i <= number; ++i)
		{
			method[i] = method[i-1] + method[i-2];	
		}
		return method[number];
	}
}

int main()
{
	cout << "0:" << RectCover(0) << endl;
	cout << "1:" << RectCover(1) << endl;
	cout << "2:" << RectCover(2) << endl;
	cout << "3:" << RectCover(3) << endl;
	cout << "4:" << RectCover(4) << endl;
	return 0;
}

