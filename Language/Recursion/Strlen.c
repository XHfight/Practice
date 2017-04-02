/*
题目：模拟实现字符串操作函数：strlen，用来计算字符串的长度。
要求不能创建任何临时变量实现。
*/

#include <stdio.h>

int my_strlen(const char *str)
{
	if(*str == '\0')
	{
		return 0;
	}
	else
	{
		return 1+my_strlen(str+1);
	}
}

int main()
{
	char str[] = "abcdefg";
	int len = my_strlen(str);
	printf("%d\n", len);
	return 0;
}