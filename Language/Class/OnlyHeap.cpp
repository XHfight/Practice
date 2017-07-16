/*************************************************************************
	> File Name: OnlyHeap.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 一  7/17 01:30:58 2017
 ************************************************************************/

//设计一个类只能在堆上创建对象
#include<iostream>
using namespace std;
//思路：只能在堆上生成对象，即在栈上生成对象会报错。在栈上创建对象如A a；这样会在类外部自动调用构造函数，当我们把构造函数设为私有，则无法调用。
//可是如果把构造函数设置为私有，则这个类不能被继承，所以要将构造函数设置为protected
class Heap_o
{
public:
	static Heap_o *GetObj()
	{
		return new Heap_o;
	}

	void Destory()
	{
		delete this;
	}
protected:
	Heap_o()
	{}
	Heap_o(Heap_o &);
};

int main()
{
	Heap_o h;
	return 0;
}
