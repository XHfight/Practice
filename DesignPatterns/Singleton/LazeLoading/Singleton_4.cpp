/*************************************************************************
	> File Name: Singleton_4.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 六  7/ 8 10:25:41 2017
 ************************************************************************/

//v4:解决死锁问题
//当程序执行临界区代码时抛出异常（这时_instence==NULL），程序无法执行解锁，其他线程都在等待加锁，程序进入死锁状态。
//解决办法：利用RAII思想，将加锁和解锁封装成一个类，构造时加锁，析构时解锁。
#include<iostream>
#include<pthread.h>
using namespace std;

//利用RAII思想，将加锁和解锁封装成一个类，构造时加锁，析构时解锁。
class Mutex
{
public:
	Mutex(pthread_mutex_t &lock)
		:m_lock(lock)
	{
		pthread_mutex_lock(&m_lock);
	}
	~Mutex()
	{
		pthread_mutex_unlock(&m_lock);
	}
private:
	pthread_mutex_t &m_lock; //必须用引用，不然就不是同一个锁，而是锁的一个临时拷贝。
};

class Singleton
{
public:
	//获取唯一对象实例的接口函数
	static Singleton* GetInstence()
	{
		//引入双检查
		if(_instence == NULL)
		{
			//创建对象自动加锁
			Mutex myLock(_lock);
			if(_instence == NULL)
			{
				_instence = new Singleton();
				// 1.分配空间 2.调用构造函数 3.赋值
			}
			//出了作用域自动解锁
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
	//保证线程安全的互斥锁
	static pthread_mutex_t _lock;
	
};

Singleton *Singleton::_instence = NULL;
pthread_mutex_t Singleton::_lock = PTHREAD_MUTEX_INITIALIZER;

int main()
{
	Singleton *s = Singleton::GetInstence();
	Singleton::DelInstence();
}
