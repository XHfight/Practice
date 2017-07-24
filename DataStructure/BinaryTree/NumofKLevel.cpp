/*************************************************************************
	> File Name: NumofKLevel.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 一  7/24 14:43:17 2017
 ************************************************************************/

#include<iostream>
using namespace std;
//求二叉树第k层的节点个数
//思路：要求第k层＝第k层的下一层的左右子树的的k－1层结点数之和。如果k＝1就是求当前树的第一层结点数，不是空树，就返回1.
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


static int _NumOfKLevel(Node *root, int k)
{
	if(root == NULL || k <=0 )
		return 0;
	
	if(k == 1)
		return 1;
	else
		return _NumOfKLevel(root->_left, k-1)+_NumOfKLevel(root->_right, k-1);

}

int NumofKLevel(Node *root, int k)
{
	return _NumOfKLevel(root, k);
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
	
	//3
	cout << NumofKLevel(root, 3) << endl;
	//4
	cout << NumofKLevel(root, 1) << endl;
	return 0;
}
