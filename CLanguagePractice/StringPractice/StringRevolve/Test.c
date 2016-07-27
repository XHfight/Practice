#include <stdio.h>

extern void LeftRevole(char str[], int num);
extern int CheckRevolve(const char *str, const char *src);


void TestLeft()
{
	char arr[10] = "AABCD";
	int num = 0;
	printf("请输入要左旋字符的个数：");
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
		printf("s2是s1旋转后的字符串\n");
	}
	else
	{
		printf("s2不是s1旋转后的字符串\n");
	
	}
}

int main()
{
//	TestLeft();
	TestCheck();
	return 0;
}