/*
问题描述:回文数 
　　1221是一个非常特殊的数，它从左边读和从右边读是一样的，编程求所有这样的四位十进制数。
输出格式
　　按从小到大的顺序输出满足条件的四位十进制数。
*/

#include <iostream>
using namespace std;

int main()
{
	int i = 1000;
	while(i <= 9999)
	{
		int one = i%10;
		int two = i/10%10;
		int thr = i/100%10;
		int fou = i/1000%10; 
		if(one==fou && two==thr)
		{
			cout << i << endl;
		}
		i++;
	}
	return 0;
} 
