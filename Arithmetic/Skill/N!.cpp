/*************************************************************************
	> File Name: N!.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 六  7/22 09:24:17 2017
 ************************************************************************/

#include<iostream>
using namespace std;
//问题：N的阶乘(N!)中的末尾有多少个0?
//思路：问题可以转换成哪些数相乘可以得到10。N!=x*(10^M); M就是末尾0的个数。
//10=2*5；N!=1^n+2^j+...+5^k所以问题最终转换成求可以分解的2的个数与可以分解出5的个数的最小值。
//又因为2出现的次数肯定比5多，所以问题最终转换成求能够分解出5的个数。
//
size_t CountZero(int N)
{
	int count = 0;
	for(int i = 5; i <= N; i+=5)
	{
		int j = i;
		while(j%5 == 0)
		{
			++count;
			j /= 5;
		}
	}
	return count;
}

int main()
{
	int N = 10;
	cout << CountZero(N) << endl;
}
