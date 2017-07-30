/*************************************************************************
	> File Name: ChangeDoublelinklist.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 日  7/30 21:43:48 2017
 ************************************************************************/

#include<iostream>
using namespace std;

//将二叉搜索树转换成一个排序的双向链表。提示：要求不能创建任何新的结点，只能调整树中结点指针的指向，也就是left当prev，right当next。--中序线索化的变型。 

//思路：left指向前一个结点，right指向后一个结点
typedef struct BinaryNode
{
	int _val;
	BinaryNode *_left;
	BinaryNode *_right;

	BinaryNode(int data)
		:_val(data)
		 ,_left(NULL)
		 ,_right(NULL)
	{}

}Node;

//根据中序遍历，根结点当前结点的左子树已经转换成双向链表，将当前链表接入双向链表中，然后继续将右子树加入双向链表中。list:已转换链表的最后一个结点。
void _ChangeDouble(Node* root, Node *&last)
{
	if(root == NULL)
		return;
	if(root->_left)
		_ChangeDouble(root->_left, last);
	
	//将结点连入链表
	root->_left = last;
	if(last) //要判断，不然第一次进来的时候链表为空，会崩溃
		last->_right = root;
	//更新链表最后一个结点
	last = root;

	if(root->_right)
		_ChangeDouble(root->_right, last);
}

Node* ChangeDoublelinklist(Node *root)
{
	//找头结点
	Node *head = root;
	while(head->_left)
		head = head->_left;

	Node *last = NULL; //标记已转换链表的最后一个结点
	_ChangeDouble(root, last);
	return head;
}

void PrintList( Node *root)
{
	Node *cur = root;
	while(cur)
	{
		cout << cur->_val << " ";
		cur = cur->_right;
	}
	cout << endl;
}
int main()
{
	Node *root = new Node(4);
	Node *n2 = new Node(2);
	Node *n6 = new Node(6);
	Node *n1 = new Node(1);
	Node *n3 = new Node(3);
	Node *n5 = new Node(5);
	Node *n7 = new Node(7);
	root->_left = n2;
	root->_right = n6;
	n2->_left = n1;
	n2->_right = n3;
	n6->_left = n5;
	n6->_right = n7;
	
	Node *ret = ChangeDoublelinklist(root);
	PrintList(ret);
	return 0;
}
