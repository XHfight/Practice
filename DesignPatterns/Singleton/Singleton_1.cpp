/*************************************************************************
	> File Name: Singleton_1.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 六  7/ 8 10:25:41 2017
 ************************************************************************/

//v1版：不考虑线程安全
//将构造函数设为私有的，提供一个接口创建实例，设置标识是接口只能被调用一次。
#include<iostream>
using namespace std;

class Singleton
{
public:
	//获取唯一对象实例的接口函数
	static Singleton* GetInstence()
	{
		if(_instence == NULL)
		{
			_instence = new Singleton();
		}
		return _instence;
	}
	//删除唯一实例的接口
	static void DelInstence()
	{
		if(_instence != NULL)
		{
			delete _instence;
			_instence = NULL;
		}
	}
private:
	Singleton()
	{}

	Singleton(const Singleton &);
	Singleton& operator=(const Singleton &);
private:
	static Singleton* _instence;
};

Singleton *Singleton::_instence = NULL;

int main()
{
	Singleton *s = Singleton::GetInstence();
	Singleton::DelInstence();
}
