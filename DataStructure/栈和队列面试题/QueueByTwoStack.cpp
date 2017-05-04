/*************************************************************************
	> File Name: 7.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Sun 18 Dec 2016 03:52:28 PM CST
 ************************************************************************/

/*
 * 用两个栈实现队列
 */

#include<iostream>
#include<stack>
#include<unistd.h>
#include<stdlib.h>
using namespace std;

template<typename T>
class CQueue
{
public:
	CQueue(void){}
	~CQueue(void){}

	void Push(const T& node);
	void Pop();
	const T& Front()
	{
		if(stack2.empty())
		{
			while(!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		if(stack2.size() == 0)
		{
			cout << "queue is empty" << endl;
			exit(1);
		}
		return stack2.top();
	}
	void Print();
	bool Empty()
	{
		return (stack1.empty()&&stack2.empty());
	}
private:
	stack<T> stack1;  //入队栈
	stack<T> stack2;  //出队栈
};

template <typename T>
void CQueue<T>::Push(const T& node)
{
	stack1.push(node);
}

template <typename T>
void CQueue<T>::Pop()
{
	if(stack1.empty() && stack2.empty())
	{
		cout << "queue is empty" << endl;
		exit(2);
	}
	if(stack2.empty())
	{
		while(!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
	}
	stack2.pop();
}

template <typename T>
void CQueue<T>::Print()
{
	while(!Empty())
	{
		cout << Front() << " ";
		Pop();
	}
	cout << endl;
}

int main()
{
	//CQueue<int> cq;
	//cq.Push(1);
	//cq.Push(2);
	//cq.Push(3);
	//cq.Push(4);
	//cq.Push(5);
	//cq.Print();
	
	CQueue<int> cq;
	cq.Push(1);
	cq.Push(2);
	cq.Push(3);
	cq.Push(4);
	cq.Pop();
	cq.Push(5);
	cq.Print();
	return 0;
}
