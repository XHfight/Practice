/*************************************************************************
	> File Name: swap.c
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 三  7/ 5 09:21:01 2017
 ************************************************************************/

#include<stdio.h>
/*
#define SWAP(a, b) \
	int tmp = a; \
	a = b; \
	b = tmp;

void Test()
{
	//错误1:变量重复定义
	SWAP(a, b);
	SWAP(a, b);
	//错误2:tmp出了作用域使用
	if(1)
		SWAP(a, b);
}
*/

//正确
#define SWAP(a, b) \
	{			\
		int tmp = a; \
		a = b; \
		b = tmp;\
	}while(0)

int main()
{
	int a =10,b = 20;
	if(1)
		SWAP(a,b);
	printf("%d %d\n", a, b);
	return 0;
}

