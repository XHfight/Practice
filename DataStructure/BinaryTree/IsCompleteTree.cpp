/*************************************************************************
	> File Name: IsCompleteTree.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 四  7/27 19:37:18 2017
 ************************************************************************/

#include<iostream>
#include<queue>
using namespace std;

//判断一棵树是否是完全二叉树
//思路：通过层序遍历，将非叶子结点的左右子树push进队列，从队列中取队头元素时如果发现null结点，则不是完全二叉树，如果整个队列中没有空元素，则是完全二叉树。

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

bool IsCompalteTree(Node *root)
{
	if(root == NULL)
		return true;
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node *cur = q.front();
		if(cur == NULL)
			return false;
		q.pop();
		if(cur->_left || cur->_right)
		{
			q.push(cur->_left);
			q.push(cur->_right);
		}
	}
	return true;
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

	cout << IsCompalteTree(root) << endl;
	Node *root1 = new Node(1);
	Node *node8 = new Node(2);
	Node *node9 = new Node(3);
	root1->_left = node8;
	root1->_right = node9;
	cout << IsCompalteTree(root1) << endl;

	return 0;
}
