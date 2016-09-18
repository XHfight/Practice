// 使用两个栈实现一个队列 

/*
解决思路：
入队时，将元素压入s1。
出队时，判断s2是否为空，如不为空，则直接弹出顶元素；如为空，则将s1的元素逐个“倒入”s2，把最后一个元素弹出并出队。
*/
#pragma once
#include <stack>
#include <iostream>
using namespace std;

template <class T>
class Queue
{
public:
	void Push(const T& data)
	{
		_s1.push(data);
	}
	void Pop()
	{
		assert((!_s1.empty()) || (!_s2.empty()));

		if (!_s2.empty())
		{
			_s2.pop();
		}
		else
		{
			while ((_s1.size())-1)
			{
				_s2.push(_s1.top());
				_s1.pop();
			}
			_s1.pop();
		}
	}
	T& Front()
	{
		assert( (!_s1.empty()) || (!_s2.empty()) );
		if (_s2.empty())
		{
			while (!_s1.empty())
			{
				_s2.push(_s1.top());
				_s1.pop();
			}
		}
		return _s2.top(); 
	}
	T& Back()
	{
		assert((!_s1.empty()) || (!_s2.empty()));
		if (_s1.empty())
		{
			while (!_s2.empty())
			{
				_s1.push(_s2.top());
				_s2.pop();
			}
		}
		return _s1.top();

	}
	size_t Size()
	{
		return _s1.size() + _s2.size();
	}
protected:

	stack<T> _s1;
	stack<T> _s2;
};