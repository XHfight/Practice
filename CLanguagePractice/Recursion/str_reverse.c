/*
��Ŀ�����õݹ�ʵ���ַ�����ת������
*/
#include <stdio.h>
#include <string.h>

void str_reverse(char *str)
{
	int len = strlen(str);
	char *left = str;
	char *right = str+len-1;
	

	if(left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = '\0';
		str_reverse(str+1);
		*right = tmp;
	}
}

int main()
{
	char arr[] = "ABCDEF";
	str_reverse(arr);
	printf("%s\n", arr);
	return 0;
}