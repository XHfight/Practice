/*************************************************************************
	> File Name: Merge.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 四  7/13 22:48:44 2017
 ************************************************************************/

//合并两个有序链表
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

//这里存在问题：当传入的两个链表交叉时，会有问题。
//所以事先应该判断两个链表是否相交。
Node* Merge(Node* head1, Node* head2)
{
	if(head1 == NULL)
		return head2;
	if(head2 == NULL)
		return head1;

	Node *newHead = NULL;
	Node *cur1 = head1;
	Node *cur2 = head2;
	if(head1->_data < head2->_data)
	{
		newHead = cur1;
		cur1 = cur1->_next;
	}	
	else
	{
		newHead = head2;
		cur2 = cur2->_next;
	}

	Node *tail=newHead;  //记录合并后链表的尾结点，以便插入结点
	while(cur1 && cur2)
	{
		if(cur1->_data < cur2->_data)
		{
			tail->_next = cur1;
			cur1 = cur1->_next;
		}
		else
		{
			tail->_next = cur2;
			cur2 = cur2->_next;
		}
		tail = tail->_next;
	}
	if(cur1)
		tail->_next = cur1;
	else
		tail->_next = cur2;
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
	Node *head1;
	Node *head2;
	Node *node1 = new Node(1);
	Node *node2 = new Node(2);
	Node *node3 = new Node(3);
	Node *node4 = new Node(4);
	Node *node5 = new Node(5);
	node1->_next = node2;
	node2->_next = node3;
	node3->_next = node4;
	node4->_next = node5;

	Node *node6 = new Node(1);
	Node *node7 = new Node(2);
	Node *node8 = new Node(3);
	Node *node9 = new Node(4);
	Node *node10 = new Node(5);
	node6->_next = node7;
	node7->_next = node8;
	node8->_next = node9;
	node9->_next = node10;

	head1 = node1;
	head2 = node6;
	
	Print(Merge(head1, head2));

	return 0;
}
