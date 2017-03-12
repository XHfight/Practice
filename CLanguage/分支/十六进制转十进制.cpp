/*
问题描述
　　从键盘输入一个不超过8位的正的十六进制数字符串，将它转换为正的十进制数后输出。
　　注：十六进制数中的10~15分别用大写的英文字母A、B、C、D、E、F表示。
样例输入
FFFF
样例输出
65535
*/

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	string src;
	cin >> src;
	int i = src.length()-1;
	long long dst = 0;
	int j = 0;
	while(i >= 0)
	{
		
		if(src[i] >= 'A' && src[i] <= 'F')
		{
			dst += pow(16, j) * ( 10 + src[i]- 'A');	
		}
		else
		{
			dst += pow(16, j) * (src[i]-'0');	
		}
		++j;
		--i;
	}
	cout << dst << endl;
	return 0;	
} 
