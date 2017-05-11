/*************************************************************************
	> File Name: FirstChar.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Thu 11 May 2017 11:52:51 PM CST
 ************************************************************************/
/*
 *对于一个字符串，请设计一个高效算法，找到第一次重复出现的字符。
 *给定一个字符串(不一定全为字母)A及它的长度n。
 *请返回第一个重复出现的字符。保证字符串中有重复字符，字符串的长度小于等于500。
 */
#include <iostream>
#include <string>
using namespace std;

char findFirstRepeat(string A, int n)
{
	int nums[256] = {0};
	string::iterator it = A.begin();
	while(it != A.end())
	{
		if(++nums[*it] == 2)
			break;
		++it;
	}
	return *it;
}

int main()
{
	string str("qwer23ptpd");
	cout << findFirstRepeat(str, str.length()) << endl;
	return 0;
}
