/*************************************************************************
	> File Name: Singleton_3.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 六  7/ 8 10:25:41 2017
 ************************************************************************/

//v3版:提高v2版本的性能
//v2版加锁带来了性能问题.加锁解锁会消耗系统性能。
//这个程序时只有在_instance==NULL的情况下才会进行new，产生线程安全问题。也就是说只有第一次进入需要加锁，后面的都不需要加锁。
//解决：引入双检查
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
		//引入双检查
		if(_instence == NULL)
		{
			pthread_mutex_lock(&mylock);
			if(_instence == NULL)
			{
				_instence = new Singleton();
				// 1.分配空间 2.调用构造函数 3.赋值
			}
			pthread_mutex_unlock(&mylock);
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
