#include <assert.h>
#include <string.h>

/*
1.ʵ��һ�����������������ַ����е�k���ַ���
AABCD����һ���ַ��õ�ABCDA
AABCD���������ַ��õ�BCDAA
*/

void LeftRevole(char str[], int num)
{
	int len = strlen(str);
	assert(str);
	assert((num>=0) && (num<=len));
	while(num--)
	{
		int tmp = str[0];
		int j = 0;
		for(; j < len-1; j++)
		{
			str[j] = str[j+1];
		}
		str[j] = tmp;
	}
	
}

/*
2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
���磺����s1 �� AABCD��s2 = BCDAA������1������s1=abcd��s2=ACBD������0.


AABCD����һ���ַ��õ�ABCDA
AABCD���������ַ��õ�BCDAA

AABCD����һ���ַ��õ�DAABC
AABCD���������ַ��õ�CDAAB
*/

int CheckRevolve(const char *str, const char *src)
{
	assert(str);
	if(strlen(str) != strlen(src))
	{
		return 0;
	}

	strncat(src, src, strlen(src));
	if(strstr(src, str))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}