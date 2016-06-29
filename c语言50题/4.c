#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num1 = 0;
	int num2 = 0;
	printf("please enter two integers:");
	scanf("%d%d",&num1,&num2);
	if(num1 < num2)
	{
		printf("较大者为：%d\n", num2);
	}
	else if(num1 == num2)
	{
		printf("相等\n");
	}
	else
	{
		printf("较大者为：%d\n", num1);
	}
	system("pause");
	return 0;
}