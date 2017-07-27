/*************************************************************************
	> File Name: Traverse_NonR.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 四  7/27 15:45:57 2017
 ************************************************************************/

#include<iostream>
#include<stack>
using namespace std;
//实现二叉树的前序/中序/后序非递归遍历。 

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

void prevOrder(Node *root)
{
	Node *cur = root;
	stack<Node*> s;

	while(!s.empty() || cur)
	{
		while(cur)
		{
			cout << cur->_val << " ";
			s.push(cur);
			cur = cur->_left; 
		}
		cur = s.top()->_right;
		s.pop();
	}
	cout << endl;
}

void InOrder(Node *root)
{
	Node *cur = root;
	stack<Node*> s;
	while(!s.empty() || cur)
	{
		while(cur)
		{
			s.push(cur);
			cur = cur->_left;
		}

		Node *top = s.top();
		cout << top->_val << " ";
		s.pop();
		cur = top->_right;
	}
	cout << endl;
}

//当前结点的右结点为空或已经被访问则访问当前结点,否则跳到他的右子树。
void LastOrder(Node *root)
{
	Node *cur = root;
	Node *prevNode = NULL;
	stack<Node*> s;
	while(!s.empty() || cur)
	{
		while(cur)
		{
			s.push(cur);
			cur = cur->_left;
		}

		Node *top = s.top();
		if(top->_right==NULL || prevNode==top->_right)
		{
			cout << top->_val << " ";
			s.pop();
			prevNode = top;
		}
		else
			cur = top->_right;
	}
	cout << endl;
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
	prevOrder(root);
	InOrder(root);
	LastOrder(root);
	return 0;
}

