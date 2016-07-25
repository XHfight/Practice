#include <stdio.h>

extern int bit_diff(int num1, int num2);
extern unsigned int reverse_bit(unsigned int value);

//3.编写一个宏将一个数的奇数位与偶数位交换
#define BIT_SWAP(NUM) \
	((NUM>>1)&0x55555555)+((NUM<<1)&0xAAAAAAAA))

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

void TestBIT_SWAP()
{
	int num = 10; //1010
	printf("%d\n", BIT_SWAP(num));
}

int main()
{
//	TestDiff();
//	TestReverse();
	TestBIT_SWAP();
	return 0;
}