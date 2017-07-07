/*************************************************************************
	> File Name: c_Polymorphism.c
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 四  7/ 6 11:06:09 2017
 ************************************************************************/

#include<stdio.h>

typedef void (*PFUN) ();

void fun_b()
{
	 printf("Base::fun\n");
}

void fun_d()
{
	printf("Derive::fun\n");
}

struct Base
{
	PFUN f;
	int _b;
};

struct Derive
{
	struct Base _base;
	int _d;
};

void fun(struct Base *pb)
{
	pb->f();
}

int main()
{
	//多态：父类指针指向父类对象调用父类函数，指向子类对象调用子类函数
	struct Base b;
	b.f = fun_b;
	fun(&b);

	struct Derive d;
	d._base.f = fun_d;
	fun(&d._base);
}
