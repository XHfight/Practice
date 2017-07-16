/*************************************************************************
	> File Name: NotInherit.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 一  7/17 01:22:09 2017
 ************************************************************************/

//设计一个不能被继承的类
#include<iostream>
using namespace std;
//思路：继承时会默认调用父类的构造函数，所以将父类的构造函数设为私有，在继承的时候就会出错，这样就需要提供接口来创建对象。

class A
{
public:
	static A *GetA()
	{
		return new A;
	}

	void Destory()
	{
		delete this;
	}
private:
	A(){}
	~A(){}
};

class B:public A
{

};

int main()
{
	B b;
	return 0;
}
