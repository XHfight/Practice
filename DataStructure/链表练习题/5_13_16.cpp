/*************************************************************************
	> File Name: 5.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Sun 20 Nov 2016 09:55:38 AM CST
 ************************************************************************/

//面试题5：逆序打印链表
//面试题13：在O（1）时间删除链表结点
//面试题15：链表中的倒数第K个结点
//面试题16：反转链表
//面试题17：合并两个排序的链表
//面试题37：两个链表的第一个公共结点

#include<iostream>
#include<stack>
#include<cassert>
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

	//5:从尾到头输出链表
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
		_head = ReverseList();
		Print();
	}

	//16:反转链表
	Node* ReverseList()
	{
		Node* cur = _head;
		Node* newHead = NULL;
		while(cur)
		{
			Node* tmp = cur;
			cur = tmp->_next;
			tmp->_next = newHead; 
			newHead = tmp;
		}
		return newHead;
	}
	//打印链表
	void Print()
	{
		Node* cur = _head;
		while(cur)
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		cout << endl;
	}
	Node* Find(DataType find)
	{
		Node* cur = _head;
		while(cur)
		{
			if(cur->_data == find)
			{
				return cur;
			}
			cur = cur->_next;
		}
		return NULL;
	}

	//面试题13：在O(1)时间删除链表结点
	//交换删除法
	void DeleteNode(Node* pToBeDeleted)
	{
		if(pToBeDeleted == NULL)
			return;
		//如果删除的结点为尾结点
		if(pToBeDeleted->_next == NULL)
		{
			if(pToBeDeleted == _head)
			{
				_head = NULL;
			}
			else
			{
				Node* cur = _head;
				while(cur && cur->_next != pToBeDeleted)
				{
					cur = cur->_next;
				}
				if(cur)
					cur->_next = NULL;
			}
			delete pToBeDeleted;
			pToBeDeleted = NULL;
			return;
		}

		Node* del = pToBeDeleted->_next;
		pToBeDeleted->_data = pToBeDeleted->_next->_data;
		pToBeDeleted->_next = pToBeDeleted->_next->_next;
		delete del;
		del = NULL;
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

void Test5()
{
	List l;
	for(int i = 1; i <= 10; ++i)
	{
		l.PushBack(i);
	}
	l.ReversePrint1();
	l.ReversePrint2();
	l.ReversePrint3();
}

void Test13()
{
	List l;
	for(int i = 1; i<=10; ++i)
	{
		l.PushBack(i);
	}
	ListNode* ret5 = l.Find(5);
	l.DeleteNode(ret5);
	ListNode* ret10 = l.Find(10);
	l.DeleteNode(ret10);
	ListNode* ret1 = l.Find(1);
	l.DeleteNode(ret1);
	l.Print();
}
int main()
{
	//Test5();
	Test13();
	return 0;
}
