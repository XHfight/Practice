/*************************************************************************
	> File Name: CountBitDiff.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Fri 12 May 2017 02:50:12 PM CST
 ************************************************************************/
/*题目描述：
 * 你知道两个int32整数m和n的二进制表达，有多少个位(bit)不同么？*/
#include<iostream>
using namespace std;

int countBitDiff(int m, int n) {
    int num = m^n;
    int count = 0;
    while(num)
    {
        if((num&1) == 1)
             ++count;
        num >>= 1;
    }
    return count;
}

int main()
{
	int m = 1999;
	int n = 2299;
	cout << countBitDiff(m, n) << endl;
	return 0;
}
