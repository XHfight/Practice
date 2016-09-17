#pragma once
//一个数组实现两个栈

#include <iostream>
#include <cassert>
#include <string.h>
using namespace std;

#define CAPACITY 10

template <class T>
class DouStack
{
public:
	DouStack()
		: _top1(-1)
		, _top2(CAPACITY)
	{}

	void Push(int nu_stack, T data)
	{
		assert(nu_stack == 1 || nu_stack == 2);
		assert(_top1 + 1 != _top2); //栈满
		
		if (nu_stack == 1)
		{
			_data[++_top1] = data;
		}
		else if (nu_stack == 2)
		{
			_data[--_top2] = data;
		}
	}

	void Pop(int nu_stack)
	{
		assert(nu_stack == 1 || nu_stack == 2);
		if (nu_stack == 1)
		{
			assert(_top1 != -1);//栈空
			_top1--;
		}
		else if (nu_stack == 2)  
		{
			assert(_top2 != CAPACITY); //栈空
			_top2++;
		}
	}

	bool Empty(int nu_stack)
	{
		assert(nu_stack == 1 || nu_stack == 2);

		return (nu_stack == 1) ? (_top1 == -1) : (_top2 == CAPACITY);
	}

	T& Top(int nu_stack)
	{
		assert(nu_stack == 1 || nu_stack == 2);

		return (nu_stack == 1) ? _data[_top1] : _data[_top2];
	}
	size_t Size(int nu_stack)
	{
		assert(nu_stack == 1 || nu_stack == 2);

		return (nu_stack == 1) ? (_top1+1) : (CAPACITY - _top2);
	}
protected:
	T _data[CAPACITY];
	int _top1;
	int _top2;
};
