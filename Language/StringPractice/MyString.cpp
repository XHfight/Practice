/*************************************************************************
	> File Name: MyString.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 三  7/ 5 10:06:55 2017
 ************************************************************************/

#include<iostream>
using namespace std;

//深拷贝
//引用计数：线程安全问题， 引用计数在堆上开辟，堆是线程共享的
class MyString
{
public:
	//不能给空串_str ＝ NULL
	MyString(const char *str="")
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}

	//传统写法
	MyString(const MyString &s)
	{
		_str = new char[strlen(s._str)+1];
		strcpy(_str, s._str);
	}
	//现代写法
	MyString(const MyString &s)
		:_str(NULL)
	{
		MyString tmp(s);
		swap(_str, tmp._str);
	}
	
	//传统写法
	MyString &operator=(const MyString &s)
	{
		if(this != &s)
		{
			char *del = _str;
			_str = new char[strlen(s._str)+1];
			strcpy(_str, s._str);
			delete[] del;
		}
		return *this;  //实现链式赋值
	}
	//现代写法
	MyString &operator=(MyString s)
	{
		swap(_str, s._str);
		return *this;
	}
	
	~MyString()
	{
		if(_str)
		{
			delete[] _str;
			_str = NULL;
		}
	}

private:
	char *_str;
};
