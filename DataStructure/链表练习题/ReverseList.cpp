/*************************************************************************
	> File Name: ReverseList.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 二  7/11 10:16:18 2017
 ************************************************************************/

//链表逆置
//1.取结点头插到新链表
//2.三个指针相互逆
#include<iostream>
using namespace std;

typedef struct ListNode
{
	int _data;
	ListNode *_next;

	ListNode(int data)
		:_data(data)
		 ,_next(NULL)
	{}

}Node;

//方法1:取结点头插
Node* Reserve(Node* head)
{
	Node* newHead = NULL;
	Node* tmp = NULL;
	Node* cur = head;
	while(cur)
	{
		tmp = cur;
		cur = cur->_next;
		tmp->_next = newHead;
		newHead = tmp;
	}
	return newHead;
}

void Print(Node* head)
{
	Node *cur = head;
	while(cur)
	{
		cout << cur->_data << "->";
		cur = cur->_next;
	}
	cout << "NULL" << endl;
}

int main()
{
	Node *node1 = new Node(1);
	Node *node2 = new Node(2);
	Node *node3 = new Node(3);
	Node *node4 = new Node(4);
	Node *node5 = new Node(5);
	node1->_next = node2;
	node2->_next = node3;
	node3->_next = node4;
	node4->_next = node5;

	Print(Reserve(node1));

	return 0;
}
