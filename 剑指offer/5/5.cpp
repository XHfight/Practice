/*************************************************************************
	> File Name: 5.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Sun 20 Nov 2016 09:55:38 AM CST
 ************************************************************************/

//逆序打印链表
#include<iostream>
#include<stack>
using namespace std;

typedef int DataType;
struct ListNode
{
	DataType _data;
	ListNode* _next;

	ListNode(DataType data)
	:_data(data)
	,_next(NULL)
	{}
};

class List
{
	typedef ListNode Node;
public:
	List()
	:_head(NULL)
	{}

	void PushBack(DataType data)
	{
		if(_head == NULL)
		{
			_head = new Node(data);
		}
		else
		{
			Node* cur = _head;
			while(cur->_next != NULL)
			{
				cur = cur->_next;
			}
			cur->_next = new Node(data);
		}
	}
	//逆序打印
	//法1：递归打印
	//缺点：如果链表太长，可能会栈溢出；函数调用开销大
	void ReversePrint1()
	{
		_ReversePrint(_head);
		cout << endl;
	}
	//法2：借助栈，后进先出
	void ReversePrint2()
	{
		Node* cur = _head;
		stack<Node*> s;
		while(cur)
		{
			s.push(cur);
			cur = cur->_next;
		}
		
		while(!s.empty())
		{
			cout << s.top()->_data << " ";
			s.pop();
		}
		cout << endl;
	}
	//法3：先逆置链表，再顺序打印。
	//缺点：改变了链表的结构
	void ReversePrint3()
	{
		//链表逆置
		Node* cur = _head;
		Node* newHead = NULL;
		while(cur)
		{
			Node* tmp = cur;
			cur = tmp->_next;
			tmp->_next = newHead; 
			newHead = tmp;
		}
		//打印
		cur = newHead;
		while(cur)
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		cout << endl;
	}
protected:
	void _ReversePrint(Node* node)
	{
		if(node == NULL)
			return;
		else
		{
			_ReversePrint(node->_next);
			cout << node->_data << " ";
		}
	}
protected:
	Node* _head;
};

int main()
{
	List l;
	for(int i = 1; i <= 10; ++i)
	{
		l.PushBack(i);
	}
	l.ReversePrint1();
	l.ReversePrint2();
	l.ReversePrint3();
	return 0;
}
