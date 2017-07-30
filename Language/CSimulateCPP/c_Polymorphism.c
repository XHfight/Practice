/*************************************************************************
	> File Name: c_Polymorphism.c
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 四  7/ 6 11:06:09 2017
 ************************************************************************/

#include<stdio.h>
//用c语言实现c++的多态机制
//思路：c++的多态用虚函数重写实现，子类继承父类，在父类对象模型的最上面有一个虚表指针，指向虚表，虚表里面存着函数的地址。
//那么就可以定义一个父类的结构体，结构体第一个成员是一个函数指针数组

typedef void (*PFUN) ();

//父类的函数
void fun_b()
{
	 printf("Base::fun\n");
}

//子类的函数
void fun_d()
{
	printf("Derive::fun\n");
}

//父类结构体：包含一个函数指针
typedef struct Base
{
	PFUN f; //函数指针
	int _b;
}Base;

//子类结构体：包含父类对象
typedef struct Derive
{
	struct Base _base;
	int _d;
}Derive;

//调用父类结构体中函数指针指向的函数
void fun(struct Base *pb)
{
	pb->f();
}

int main()
{
	//多态：父类指针指向父类对象调用父类函数，指向子类对象调用子类函数
	Base b;
	b.f = fun_b;
	Base *p = &b;//父类指针指向父类对象
	fun(p);   //调用父类函数

	Derive d;
	d._base.f = fun_d; //相当于重写
	p = (Base *)&d; //父类指针指向子类对象
	fun(p);  //调用子类函数
}
