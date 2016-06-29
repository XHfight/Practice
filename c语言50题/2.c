#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0;
	int sum = 1;
	for(i = 2; i <= 100; i++)
	{
		sum += i;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}