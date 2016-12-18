#include <assert.h>
#include <string.h>

/*
1.实现一个函数，可以左旋字符串中的k个字符。
AABCD左旋一个字符得到ABCDA
AABCD左旋两个字符得到BCDAA
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
2.判断一个字符串是否为另外一个字符串旋转之后的字符串。
例如：给定s1 ＝ AABCD和s2 = BCDAA，返回1，给定s1=abcd和s2=ACBD，返回0.


AABCD左旋一个字符得到ABCDA
AABCD左旋两个字符得到BCDAA

AABCD右旋一个字符得到DAABC
AABCD右旋两个字符得到CDAAB
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