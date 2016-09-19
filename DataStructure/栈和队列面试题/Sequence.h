//元素出栈、入栈顺序的合法性。如入栈的序列（1, 2, 3, 4, 5），出栈序列为（4, 5, 3, 2, 1）

#pragma once
#include <iostream>
#include <stack>
using namespace std;

template <class T>
bool IsLegal(const T* src, const T* dst, size_t size1, size_t size2) //src为入栈序列，dst为出栈序列
{
	assert(src && dst);
	stack<T> s;

	if (size1 != size2)
	{
		return false;
	}
	while (size1 != 0)
	{
		if (*src == *dst)
		{
			++src;
			++dst;
			--size2;
			--size1;

		}
		else
		{
			if (!s.empty() && s.top() == *dst)
			{

				s.pop();
				++dst;
				--size2;
			}
			else
			{
				s.push(*src);
				++src;
				--size1;
			}
		}
	}
	while (size2 != 0 && *dst == s.top())
	{
		s.pop();
		++dst;
		--size2;
	}

	if (s.empty())
	{
		return true;
	}

	return false;
}
