/*
��Ŀ��ģ��ʵ���ַ�������������strlen�����������ַ����ĳ��ȡ�
Ҫ���ܴ����κ���ʱ����ʵ�֡�
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