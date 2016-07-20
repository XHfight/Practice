#include <stdio.h>

extern int bit_diff(int num1, int num2);
extern unsigned int reverse_bit(unsigned int value);

void TestDiff()
{
	int num1 = 10; //1010
	int num2 = 8;  //1000
	printf("different:%d\n",bit_diff(num1, num2));
}

void TestReverse()
{
	int num1 = 1;
	int num2 = 10;

	printf("%u\n", reverse_bit(num1));
	printf("%u\n", reverse_bit(num2));
}
int main()
{
	TestDiff();
	TestReverse();
	return 0;
}