/*************************************************************************
	> File Name: Singleton_1.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 六  7/ 8 10:25:41 2017
 ************************************************************************/

//v2版：线程安全的版本，但是有性能问题
//给v1版的NULL == _instence部分加锁，解决了线程安全问题，却带来了性能问题.
#include<iostream>
#include<pthread.h>
using namespace std;

pthread_mutex_t mylock = PTHREAD_MUTEX_INITIALIZER;
class Singleton
{
public:
	//获取唯一对象实例的接口函数
	static Singleton* GetInstence()
	{
	
		pthread_mutex_lock(&mylock);
		if(_instence == NULL)
		{
			_instence = new Singleton();
			// 1.分配空间 2.调用构造函数 3.赋值
		}
		pthread_mutex_unlock(&mylock);
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
