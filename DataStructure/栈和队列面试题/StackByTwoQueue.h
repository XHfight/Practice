//使用两个队列实现一个栈 
#pragma once
#include <iostream>
#include <queue>
using namespace std;

template <class T>
class Stack
{
public:
	void Push(const T& data)
	{
		if (!_q1.empty())
			_q1.push(data);
		else
			_q2.push(data);
	}
	void Pop()
	{
		assert(!_q1.empty() || !_q2.empty());
		if (!_q1.empty())
		{
			while (_q1.size()-1)
			{
				_q2.push(_q1.front());
				_q1.pop();
			}
			_q1.pop();
		}
		else
		{
			while (_q2.size() - 1)
			{
				_q1.push(_q2.front());
				_q2.pop();
			}
			_q2.pop();
		}
	}
	size_t Size()
	{
		return _q1.size() + _q2.size();
	}
	T& Top()
	{
		assert(!_q1.empty() || !_q2.empty());
		return (_q1.empty()) ? _q2.back() : _q1.back();
	}
	bool Empty()
	{
		return _q1.empty()&&_q2.empty();
	}
protected:
	queue<T> _q1;
	queue<T> _q2;
};