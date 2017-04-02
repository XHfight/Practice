#include <assert.h>
#include <string.h>

//1.
//��һ���ַ����������Ϊ:"student a am i",���㽫��������ݸ�Ϊ"i am a student".
//Ҫ��
//����ʹ�ÿ⺯����ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���

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

//2.�ַ����滻�ո�
//��ʵ��һ�����������ַ������е�ÿ���ո��滻�ɡ���20����
//�������롰we are happy.�����������we%20are%20happy.����

void StringReplace(char* str, int size)
{
	int count_space = 0;
	int len = strlen(str);
	int newlen = 0;
	char *cp = str;
	assert(str);

	while(*cp)     //ͳ�ƿո������
	{
		if(*cp == ' ')
		{
			count_space++;
		}
		cp++;
	}

	newlen = len + 2*count_space; //�������ַ����ĳ���

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
