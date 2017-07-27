/*************************************************************************
	> File Name: NodeIsExist.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 四  7/27 18:58:06 2017
 ************************************************************************/

#include<iostream>
using namespace std;
//判断一个节点是否在一棵二叉树中。（注意多测几个节点，看是否都能找到） 

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

bool IsExist(Node *root, int find)
{
	if(root == NULL)
		return false;
	if(root->_val == find)
		return true;
	return (IsExist(root->_left, find) || IsExist(root->_right, find));
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
	cout << IsExist(root, 1) << endl;
	cout << IsExist(root, 2) << endl;
	cout << IsExist(root, 3) << endl;
	cout << IsExist(root, 4) << endl;
	cout << IsExist(root, 5) << endl;
	cout << IsExist(root, 6) << endl;
	cout << IsExist(root, 7) << endl;
	cout << IsExist(root, 8) << endl;
	cout << IsExist(root, 9) << endl;
	return 0;
}
