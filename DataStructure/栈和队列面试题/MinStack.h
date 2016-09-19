//ʵ��һ��ջ��Ҫ��ʵ��Push����ջ����Pop����ջ����Min��������Сֵ�Ĳ�������ʱ�临�Ӷ�ΪO(1��
#pragma once

#include <iostream>
#include <stack>
using namespace std;

template <class T>
class MinStack
{
public:
	void Push(const T& data)
	{
		_data.push(data);
		if (_min.empty() || _min.top() >= data)
		{
			_min.push(data);
		}
	}
	void Pop()
	{
		assert(!_data.empty());
		if (_min.top() == _data.top())
		{
			_min.pop();
		}
		_data.pop();
	}
	const T& Top() const
	{
		assert(!_data.empty());
		return _min.top();
	}
	size_t Size()
	{
		return _data.size();
	}
	bool Empty()
	{
		return _data.empty();
	}
protected:
	stack<T> _data;
	stack<T> _min;
};