/*************************************************************************
	> File Name: IsLoop.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 日  7/16 11:02:18 2017
 ************************************************************************/

//判断链表是否带环？若带环求环的长度？若带环求环的入口点？并计算以上每个问题的时间复杂度？
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

//链表判环：快慢指针，快指针一次走两步，慢指针一次走一步，若能相遇，则链表带环。
//时间复杂度：O(N),当慢指针进入环后，在一圈内一定会被快指针追上。
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

//求环的长度:从相遇点走一圈到相遇点，统计环的长度
//时间复杂度：O(N) 环的长度
size_t LengthOfLoop(Node *meet)
{
	assert(meet);
	Node *cur = meet->_next;
	size_t len = 1;
	while(cur != meet)
	{
		len++;
		cur = cur->_next;
	}
	return len;
}

//求环入口点：两个指针，一个从链表头走，一个从相遇点走，当两个指针相等时就是入口点。
//时间复杂度：O(N) 
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

	node5->_next = node3;
	
	Node *meet = NULL; 
	if((meet = IsLoop(node1)) == NULL)
	{
		cout << "Not Find Loop" << endl;
	}
	else
	{
		cout << "Find Loop" << endl;
		cout << "Length of loop:" << LengthOfLoop(meet) << endl;
		cout << "entry point:" << EntryPoint(node1, meet)->_data << endl;
	}

	return 0;
}
