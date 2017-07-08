/*************************************************************************
	> File Name: Singleton_6.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 六  7/ 8 10:25:41 2017
 ************************************************************************/

//v6:利用RAII思想自动销毁对象
//可以在类内部再声明一个内部类，然后用内部类创建一个全局变量，用来管理实例的销毁。因为在程序运行时结束时，系统会销毁所有的全局变量。所以系统会调用内部类的析构函数，该析构函数会删除单例模式的唯一实例。
#include<iostream>
#include<pthread.h>
#include <libkern/OSAtomic.h>
using namespace std;

//利用RAII思想，将加锁和解锁封装成一个类，构造时加锁，析构时解锁。防止死锁.
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
			//	_instence = new Singleton();
				// 1.分配空间 2.调用构造函数 3.赋值
				//2,3可能被优化，颠倒顺序
				//解决：加入内存栅栏进行处理,防止编译器重排栅栏后面的到栅栏之前.
				Singleton *tmp = new Singleton();
				OSMemoryBarrier();  //内存屏障/栅栏
				_instence = tmp;
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

	//内部类
	class GC
	{
	public:
		~GC()
		{
			DelInstence();
		}
	};
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
Singleton::GC gc; //创建全局的内部类对象，当程序执行完时会销毁所有全局变量，自动调用其析构函数，从而释放单例。

int main()
{
	Singleton *s = Singleton::GetInstence();
	Singleton::DelInstence();
}
