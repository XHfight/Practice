/*************************************************************************
	> File Name: HighOfTree.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 一  7/24 15:06:57 2017
 ************************************************************************/

#include<iostream>
using namespace std;

//求当前树的高度
//思路：左右子数高度的较大者＋1

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

int _HighOfTree(Node *root)
{
	if(root == NULL)
		return 0;
	if(root->_left==NULL && root->_right==NULL)
		return 1;
	int left = _HighOfTree(root->_left);
	int right = _HighOfTree(root->_right);

	return (left>right)?left+1:right+1;
}

int HighOfTree(Node *root)
{
	return _HighOfTree(root);
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
	cout << HighOfTree(root) << endl; //4
	return 0;
}
