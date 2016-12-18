#include <math.h>

//1.编程实现：
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
//输入例子:
//1999 2299
//输出例子:7

int bit_diff(int num1, int num2)
{
	int num = 0;
	int count = 0;
	num = num1^num2;
	while(num)
	{
		num = num & (num-1);
		count++;
	}
	return count;
}


//2.编写函数：
//unsigned int  reverse_bit(unsigned int value);
//这个函数的返回 值value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//          2550136832

//方法1
//unsigned int reverse_bit(unsigned int value)
//{
//	unsigned int reverse = 0;
//	int i = 0;
//	for(; i<32; ++i)
//	{
//		reverse += (unsigned int)(value&1)*pow(2, 31-i);
//		value >>= 1;
//	}
//	return (unsigned int)reverse;
//}

//方法二
unsigned int reverse_bit(unsigned int value)
{
	unsigned int reverse = 0;
	int i = 0;
	for(i = 0; i<32; ++i)
	{
		reverse <<= 1;
		reverse |= ((value>>i)&1);
	}
	return (unsigned int)reverse;
}


