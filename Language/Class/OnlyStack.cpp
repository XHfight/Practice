/*************************************************************************
	> File Name: OnlyStack.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 一  7/17 01:45:41 2017
 ************************************************************************/

//设计一个类只能在栈上创建对象
#include<iostream>
using namespace std;
//思路：将operator new 和operator delete 重载为私有。
class Stack_o
{
private:
	void *operator new(size_t);
	void operator delete(void *ptr);
};


int main()
{
	Stack_o *p = new Stack_o;	
	return 0;
}

