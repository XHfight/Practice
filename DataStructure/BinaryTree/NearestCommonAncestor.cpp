/*************************************************************************
	> File Name: NearestCommonAncestor.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 四  7/27 20:15:42 2017
 ************************************************************************/

#include<iostream>
using namespace std;

//求二叉树中两个节点的最近公共祖先。 
//要求考虑以下三种种情况，给出解决方案，并解决： 
//1：二叉树每个节点有parent（三叉链） 
//2：二叉树是搜索二叉树。 
//3：就是普通二叉树。（尽可能实现时间复杂度为O（N））

//思路：
//1.可以转换成求链表相交问题
//2.如果当前结点比两个结点最小值小，向右子树找；
//	如果当前结点比两个结点最大值大，向左子树找；
//	如果当前结点处于两个结点值之间，则该结点就是最近公共祖先。
//3.两种方法：
//1)记录根结点到两个结点的路径，让后对比路径，第一个不相同的结点的前一个就是就近公共祖先。
//2)递归：同时找两个结点，利用一个返回值接收，如果两个结点都在左子树或都在右子树，就会返回李根结点最近的那个结点，如果两个结点分别在左子树和右子树，则返回根结点。

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

//实现第三种情况的方法二：
Node* _NearestCommonAncestor(Node* root, Node* n1, Node *n2)
{
	if(root == NULL)
		return NULL;

	if(root == n1 || root == n2)
		return root;

	Node *left = _NearestCommonAncestor(root->_left, n1, n2);
	Node *right = _NearestCommonAncestor(root->_right, n1, n2);

	if( left && right)
		return root;
	return left ? left :right;
}

Node* NearestCommonAncestor(Node* root, Node* n1, Node *n2)
{
	return _NearestCommonAncestor(root, n1, n2);
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
	cout << NearestCommonAncestor(root, node6, node7)->_val << endl; //3
	cout << NearestCommonAncestor(root, node5, node6)->_val << endl; //1
	return 0;
}
