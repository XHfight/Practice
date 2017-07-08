/*************************************************************************
	> File Name: Singleton.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 日  7/ 9 01:10:51 2017
 ************************************************************************/

#include<iostream>
#include<cassert>
using namespace std;
//方法一：在GetInstence内部创建静态的类的实例
class Singleton
{
public:
	static Singleton* GetInstence()
	{
		static Singleton sInstence;
		return &sInstence;
	}
private:
	Singleton()
	{}
	Singleton(const Singleton &);
	Singleton &operator=(const Singleton &);
};

//实现方式二:将指向对象的指针作为类的静态成员变量，在类外对其初始化时new一个类的对象。
class Singleton2
{
public:
	static Singleton2* GetInstence()
	{
		assert(psInstence);
		return psInstence;
	}
private:
	Singleton2()
	{}
	Singleton2(const Singleton2 &);
	Singleton2 &operator=(const Singleton2 &);
private:
	static Singleton2* psInstence;
};
Singleton2* Singleton2::psInstence = new Singleton2();


int main()
{
	Singleton::GetInstence();
	Singleton2::GetInstence();
	return 0;
}
