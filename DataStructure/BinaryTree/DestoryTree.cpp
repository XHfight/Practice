/*************************************************************************
	> File Name: DestoryTree.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 一  7/24 15:15:27 2017
 ************************************************************************/

#include<iostream>
using namespace std;
//销毁一棵二叉树

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

void Destory(Node *root)
{
	if(root == NULL)
		return ;
	Destory(root->_left);
	Destory(root->_right);

//	cout << root->_val<< " ";
	delete root;
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
	Destory(root);
	return 0;
}
