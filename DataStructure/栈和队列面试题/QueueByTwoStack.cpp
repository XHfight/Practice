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
using namespace std;


template<typename T>
class CQueue
{
public:
	CQueue(void){}
	~CQueue(void){}

	void appendTail(const T& node);
	T deleteHead();

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
void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);
}

template <typename T>
T CQueue<T>::deleteHead()
{
	if(stack2.empty())
	{
		while(!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
	}
	T tmp = stack2.top();
	stack2.pop();
	return tmp;
}

template <typename T>
void CQueue<T>::Print()
{
	while(!Empty())
	{
		cout << deleteHead() << " ";
	}

	cout << endl;
}

int main()
{
	//CQueue<int> cq;
	//cq.appendTail(1);
	//cq.appendTail(2);
	//cq.appendTail(3);
	//cq.appendTail(4);
	//cq.appendTail(5);
	//cq.Print();
	
	CQueue<int> cq;
	cq.appendTail(1);
	cq.appendTail(2);
	cq.appendTail(3);
	cq.appendTail(4);
	cq.deleteHead();
	cq.appendTail(5);
	cq.Print();
	return 0;
}
