#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num[10];
	int max;
	int i = 0;
	printf("please enter ten integers:\n");
	for(i = 0; i < 10; i++)
	{
		scanf("%d", &num[i]);
	}
	max = num[0];
	for(i = 1; i < 10; i++)
	{
		if(max < num[i])
		{
			max = num[i];
		}
	}
	printf("×î´ó:%d\n", max);
	system("pause");
	return 0;
}