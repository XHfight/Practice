/*************************************************************************
	> File Name: Intersect.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 一  7/17 01:57:00 2017
 ************************************************************************/

//判断两个链表是否相交，若相交，求交点。（假设链表不带环）2.判断两个链表是否相交，若相交，求交点。（假设链表可能带环） 

#include<iostream>
#include<cassert>
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

//链表判环，返回相遇点
Node * IsLoop(Node *head)
{
	Node *slow = head;
	Node *fast = head;
	while(slow && fast && fast->_next)
	{
		if(slow != head && slow == fast)  //进来第一次slow和fast相等，要排除
			return slow;
		slow = slow->_next;
		fast = fast->_next->_next;
	}
	return NULL;
}

//求环入口点
Node *EntryPoint(Node* head, Node *meet)
{
	assert(head);
	assert(meet);
	Node* cur1 = meet;
	Node* cur2 = head;
	while(cur1 != cur2)
	{
		cur1 = cur1->_next;
		cur2 = cur2->_next;
	}
	return cur1;
}
//判断两个链表（带环）是否相交，求交点

Node *IsIntersect_L(Node *head1, Node *head2)
{
	Node* meet1 = IsLoop(head1);
	Node* meet2 = IsLoop(head2);
	if(head1==NULL && head2 == NULL) //两个链表都不带环
	{
		//思路：
		//方法1:遍历两个链表看最后一个结点是否相同。计算出两条链表的长度，让长的先走｜len1-len2｜步,然后一起走，第一个相同的结点是第一个交点。
		//方法2:构环：用一个链表的尾，指向另一个链表的头，如果有环，则相交，交点为环入口点。
		size_t len1 = 0;
		size_t len2 = 0;
		Node *cur1 = head1;
		Node *cur2 = head2;
		while(cur1)
		{
			++len1;
			cur1 = cur1->_next;
		}
		while(cur2)
		{
			++len2;
			cur2 = cur2->_next;
		}

		cur1 = head1;
		cur2 = head2;
		size_t k;
		if(len1 > len2 )
		{
			k = len1-len2;
			while(k--)
			{
				cur1 = cur1->_next;
			}
		}
		else
		{
			k = len2 - len1;
			while(k--)
			{
				cur2 = cur2->_next;
			}
		}

		while(cur1 && cur2)
		{
			if(cur1 == cur2)
			{
				return cur1;
			}
			cur1 = cur1->_next;
			cur2 = cur2->_next;
		}
		return NULL;

	}
	else if((head1==NULL&&head2!=NULL) || (head1!=NULL&&head2==NULL))
		return NULL;   //一个带环，一个不带环，必定不相交
	else  //两个链表都带环
	{
		//判断两带环链表是否相交：即检查两个链表的相遇点是否在一个环上。
		//从一个链表的相遇点走，找另一个链表的相遇点，如果找一圈后回到自己仍没有找到第二个链表的相遇点，两相遇点不在一个环上，链表不相交，如果找到，则证明链表相交。
		Node *cur = meet1;
		do
		{
			if(cur == meet2)
				break;
			cur = cur->_next;
		}while(cur != meet1);
		
		if(cur != meet2)//不相交
		{
			return NULL;
		}
		else//带环链表相交
		{
			//相交分两种情况：
			//1.交点在环上
			//2.交点不在环上
			//求两链表的环入口点，如果入口点一样，交点不在环上，否则，交点在环上。（特例：交点刚好在环入口点上）
			Node *entry1 = EntryPoint(head1, meet1);
			Node *entry2 = EntryPoint(head2, meet2);
			if(entry1 == entry2)  //交点不在环上
			{
				//计算从链表头到入口点之间的距离，让长的先走｜len1-len2｜步，然后一起走。
				Node *l1 = head1;
				Node *l2 = head2;
				size_t len1 = 0;
				size_t len2 = 0;
				while(l1 != entry1)
				{
					++len1;
					l1 = l1->_next;
				}
				while(l2 != entry2)
				{
					++len2;
					l2 = l2->_next;
				}
				
				l1 = head1;
				l2 = head2;
				int k;
				if(len1 > len2)
				{
					k = len1-len2;
					while(k--)
					{
						l1 = l1->_next;
					}
				}
				else
				{
					k = len2 - len1;
					while(k--)
					{
						l2 = l2->_next;
					}
				}

				//把交点刚好在环入口点的情况也要处理上
				while(l1 != entry1->_next && l2 != entry2->_next)
				{
					if(l1 == l2)
						break;
					l1 = l1->_next;
					l2 = l2->_next;
				}
				return l1;
			}
			else //交点在环上，返回任意一个环入口点
			{
				return entry1;
			}
		}
		
	}

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

	return 0;
}
