/*************************************************************************
	> File Name: SortList.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 二  7/11 10:18:20 2017
 ************************************************************************/

//链表排序
//1.插入：可以。效率特别低，必须记录头结点，从前往后插
//2.冒泡：可以。
//3.选择：可以。
//4.堆排：不行。静态二叉树
//5.快排：可以。只能用前后指针法。
//6.归并：可以。比较复杂，STL的list中的sort用的归并。

//链表排序归并最好
//快排小区间优化不用插入
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

//冒泡排序
void BubbleSort(Node *head)
{
	//无结点或只有一个结点不需要排序
	if(head==NULL || head->_next== NULL)
	{
		return;
	}

	Node *tail = NULL; //tail指向停止的位置,链表最后一个位置的下一个位置
	Node *prev = head; //比较的第一个数
	while(tail != head->_next)//最后一趟比较第一个和第二个数，tail = next;所以不排
    //序的终止条件为head->_next != tail;
	{
		Node *next = prev->_next; //比较的第二个数
		while(prev->_next != tail)
		{
			next = prev->_next;
			if(prev->_data > next->_data)
			{
				swap(prev->_data, next->_data);
			}
			prev = prev->_next;
		}
		tail = next;
		prev = head;
	}
}

//前后指针法
//思路：
//prev指向（cur已经走过的）最后一个<=key的值
//cur向后找小
//交换prev++和cur的值
//让prev++,仍指向最后一个小于key的值
//cur++
//cur继续向后面找小

Node* _Partation(Node* begin, Node* end)  //左闭右开区域
{
	int key = begin->_data;
	Node* prev = begin;
	Node* cur = begin->_next;
	while(cur != end)
	{
		while(cur!=end && cur->_data >= key)  //cur找小
		{
			cur = cur->_next;
		}
		if(cur!=end)
		{
			swap(prev->_next->_data, cur->_data);
			prev = prev->_next;
			cur = cur->_next;
		}
	}
	swap(begin->_data, prev->_data);
	return prev;
}

//快排
void QuickSort(Node* head, Node* tail) //左闭右开区间
{
	if(head==NULL || head==tail || head->_next==tail) //当只有一个节点或者没有结点时停止递归
		return;
	
	Node* mid = _Partation(head, tail);
	QuickSort(head, mid);
	QuickSort(mid+1, tail);
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
	Node *node1 = new Node(5);
	Node *node2 = new Node(2);
	Node *node3 = new Node(3);
	Node *node4 = new Node(9);
	Node *node5 = new Node(1);
	node1->_next = node2;
	node2->_next = node3;
	node3->_next = node4;
	node4->_next = node5;

//	BubbleSort(node1);
	QuickSort(node1, NULL);
	Print(node1);

	return 0;
}

