/*************************************************************************
	> File Name: IsBalance.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 一  7/24 22:01:40 2017
 ************************************************************************/

#include<iostream>
#include<math.h>
using namespace std;
//判断一棵二叉树是否是平衡二叉树
//平衡:左右子树高度差不大于1

typedef struct BinaryTreeNode
{
	int _val;
	BinaryTreeNode* _left;
	BinaryTreeNode* _right;

	BinaryTreeNode(int val)
		:_val(val)
		 ,_left(NULL)
		 ,_right(NULL)
	{}
}Node;

bool _IsBalance(Node *root, size_t &high)
{
	if(root == NULL)
	{
		high = 0;
		return true;
	}

	if(root->_left == NULL && root->_right == NULL)
	{
		high = 1;
		return true;
	}

	if(_IsBalance(root->_left, high) == false)
		return false;
	int high_left = high;
	if(_IsBalance(root->_right, high) == false)
		return false;
	int high_right = high;

	high = (high_left>high_right)?high_left+1:high_right+1;

	return (abs(high_left-high_right)>1)?false:true;
}

bool IsBalance(Node *root)
{
	size_t high = 0;
	return _IsBalance(root, high);
}

int main()
{
	Node *root = new Node(1);
	Node *node2 = new Node(2);
	Node *node3 = new Node(3);
	Node *node4 = new Node(4);
	Node *node5 = new Node(5);
	Node *node6 = new Node(6);
	Node *node7 = new Node(7);
	root->_left = node2;
	root->_right = node3;
	node2->_left = node4;
	node4->_left = node5;
	node3->_left = node6;
	node3->_right = node7;
	
	//0
	cout << IsBalance(root) << endl;


	Node *root2 = new Node(1);
	Node *n2 = new Node(2);
	Node *n3 = new Node(3);
	Node *n4 = new Node(4);
	root2->_left = n2;
	root2->_right = n3;
	n2->_left = n4;
	//1
	cout << IsBalance(root2) << endl;
	return 0;
}
