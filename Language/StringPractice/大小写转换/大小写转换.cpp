/*
题目：
编写一个程序，输入一个字符串（长度不超过20），然后把这个字符串内的每一个字符进行大小写变换，即将大写字母变成小写，小写字母变成大写，然后把这个新的字符串输出。
　　输入格式：输入一个字符串，而且这个字符串当中只包含英文字母，不包含其他类型的字符，也没有空格。
　　输出格式：输出经过转换后的字符串。
*/

#include <iostream>
#include <string>
using namespace std;
void TransformStr(string &str)
{
	int len = str.length();
	for(int i = 0; i < len; ++i)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i]-('a'-'A');
		else
			str[i] = str[i]+('a'-'A');
	}
}

int main()
{
	string str;
	cin >> str;
	TransformStr(str);
	cout << str << endl;
	return 0;
}