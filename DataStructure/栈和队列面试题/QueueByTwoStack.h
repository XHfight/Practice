// ʹ������ջʵ��һ������ 

/*
���˼·��
���ʱ����Ԫ��ѹ��s1��
����ʱ���ж�s2�Ƿ�Ϊ�գ��粻Ϊ�գ���ֱ�ӵ�����Ԫ�أ���Ϊ�գ���s1��Ԫ����������롱s2�������һ��Ԫ�ص��������ӡ�
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