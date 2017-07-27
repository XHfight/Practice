/*************************************************************************
	> File Name: IsSubtree.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 四  7/27 19:04:54 2017
 ************************************************************************/

#include<iostream>
using namespace std;

//判断一颗二叉树是是否是另一颗树的子树
//思路：
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

bool IsSame(Node *h1, Node *h2)
{
	if(h1 == NULL && h2 == NULL)
	{
		return true;
	}

	if(h1==NULL || h2 == NULL)
		return false;

	if(h1->_val == h2->_val)
		return (IsSame(h1->_left, h2->_left) && IsSame(h1->_right, h2->_right));
	else
		return false;
}

bool IsSubtree(Node *root, Node *root2)
{
	if(root == NULL)
		return false;
	if(root->_val == root2->_val)
	{
		return IsSame(root, root2);
	}
	return (IsSubtree(root->_left, root2) || IsSubtree(root->_right, root2));
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

	Node *root2 = new Node(3);
	Node *node8 = new Node(6);
	Node *node9 = new Node(7);
	root2->_left = node8;
	root2->_right = node9;

	cout<< IsSubtree(root, root2) << endl;
	return 0;
}
