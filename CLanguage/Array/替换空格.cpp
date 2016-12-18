/*************************************************************************
	> File Name: 4.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Sat 29 Oct 2016 08:37:43 PM CST
 ************************************************************************/
/*
 *替换空格
 *请实现一个函数，把字符串中的每个空格替换成“%20”.
 * 例如：输入“we are happy.”,则输出“we%20are%20happy.”
 */

#include<iostream>
#include<cstring>
#include<stdio.h>
#include<cassert>
using namespace std;
void ReplaceSpace(char* str)
{
	/*
	 *思路：先将空格个数统计出来,然后计算出新字符串大小，进行移动。
	 * */
	assert(str);
	size_t count = 0;
	char* cp = str;
	while(*cp)
	{
		if(*cp == ' ')
			++count;
		++cp;
	}
	
	size_t size = strlen(str)+1;
	for(int i = size-1; i >= 0; --i)
	{
		if(str[i] != ' ')
		{
			size_t index = i+count*2;
			str[index] = str[i]; 
		}
		else// ==
		{
			size_t index = i+(--count*2);
			str[index] = '%';
			str[index+1] = '2';
			str[index+2] = '0';
			if(count == 0)
				break;
		}
	}
}
int main()
{
	char arr[50] = "h l e";
//	cin >> arr;
	ReplaceSpace(arr);
	cout << arr << endl;
	return 0;
}
