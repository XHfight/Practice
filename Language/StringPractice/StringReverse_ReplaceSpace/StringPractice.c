#include <assert.h>
#include <string.h>

//1.
//有一个字符数组的内容为:"student a am i",请你将数组的内容改为"i am a student".
//要求：
//不能使用库函数。只能开辟有限个空间（空间个数和字符串的长度无关）。

void StringReverse(char *start, char *end)
{
	assert(start && end);

	while(start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

int my_strlen(const char *str)
{
	const char *cur = str;
	assert(str);
	while(*cur++);
	return cur-str-1;
}

void WordReverse(char* str)
{
	char *start = NULL;
	char *end = NULL;
	assert(str);
	start = str;
	end = str;

	StringReverse(str, str+my_strlen(str)-1);

	while(*end)
	{
		while((*end != ' ' ) && (*end != '\0'))
		{
			end++;
		}
		end--;
		
		StringReverse(start, end);
		
		if(*(end+1) != '\0')
		{
			start = end+2;
			end = start;
		}
		end++;
	}
}

//2.字符串替换空格：
//请实现一个函数，把字符数组中的每个空格替换成“％20”。
//例如输入“we are happy.”，则输出“we%20are%20happy.”。

void StringReplace(char* str, int size)
{
	int count_space = 0;
	int len = strlen(str);
	int newlen = 0;
	char *cp = str;
	assert(str);

	while(*cp)     //统计空格的数量
	{
		if(*cp == ' ')
		{
			count_space++;
		}
		cp++;
	}

	newlen = len + 2*count_space; //计算新字符串的长度

	if(size < newlen+1)
	{
		return;
	}
	
	while(newlen != len)
	{
		if(str[len-1] == ' ')
		{
			newlen -= 3;
			str[newlen] = '%';
			str[newlen+1] = '2';
			str[newlen+2] = '0';
		}
		else
		{
			str[newlen-1] = str[len-1];
			newlen--;
		}
		len--;
	}
}
