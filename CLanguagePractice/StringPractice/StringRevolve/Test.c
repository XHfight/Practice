#include <stdio.h>

extern void LeftRevole(char str[], int num);
extern int CheckRevolve(const char *str, const char *src);


void TestLeft()
{
	char arr[10] = "AABCD";
	int num = 0;
	printf("������Ҫ�����ַ��ĸ�����");
	scanf("%d", &num);
	LeftRevole(arr, num);
	printf("%s\n", arr);
}

void TestCheck()
{
	char s1[15] = "AABCD";
//	char s2[10] = "BCDAA";
//	char s2[10] = "CBDAA";
	char s2[10] = "CDAA";

	if(CheckRevolve(s2, s1))
	{
		printf("s2��s1��ת����ַ���\n");
	}
	else
	{
		printf("s2����s1��ת����ַ���\n");
	
	}
}

int main()
{
//	TestLeft();
	TestCheck();
	return 0;
}