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
		printf("�ϴ���Ϊ��%d\n", num2);
	}
	else if(num1 == num2)
	{
		printf("���\n");
	}
	else
	{
		printf("�ϴ���Ϊ��%d\n", num1);
	}
	system("pause");
	return 0;
}