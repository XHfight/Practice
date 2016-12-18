#include <stdio.h>
//大端模式（Big_endian）:字数据的高字节存储在低地址中，低字节存储在高地址中。
//小端模式（Little_endian）:字数据的高字节存储在高地址中，低字节存储在低地址中。

//编写一个程序，检查机器是大端模式还是小端模式。

//方法1
//int CheckLittle_endian()
//{
//	int i = 1;
//	char *p = (char *)&i;
//	if(*p == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}

//方法2
int CheckLittle_endian()
{
	union check
	{
		int i;
		char a;
	}c;
	c.i = 1;
	if(c.a == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	if(CheckLittle_endian())
	{
		printf("小端模式\n");
	}
	else
	{
		printf("大端模式\n");
	}
	return 0;
}