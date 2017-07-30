/*************************************************************************
	> File Name: Rebuild.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 日  7/30 16:24:39 2017
 ************************************************************************/

#include<iostream>
#include<stack>
#include<cassert>
using namespace std;
//题目：根据二叉树的前序遍历和中序遍历重建二叉树
//由前序遍历和中序遍历重建二叉树（前序序列：1 2 3 4 5 6 - 中序序列:3 2 4 1 6 5)

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

//按前序遍历的顺序创建结点
//right不要设置为size_t，会溢出
Node *_Rebuild(int *prevOrder, int *inOrder, size_t &prevIndex, int left, int right)
{
	if(left > right)
		return NULL;

	Node *root = new Node(prevOrder[prevIndex]);
	
	//检查当前结点在中序遍历中的位置
	int index = -1;
	for(size_t i = left; i <= right; ++i)
	{
		if(inOrder[i] == prevOrder[prevIndex])
		{
				index = i;
				break;
		}
	}
	assert(index != -1);
	++prevIndex;

	root->_left = _Rebuild(prevOrder, inOrder, prevIndex, left, index-1);
	root->_right = _Rebuild(prevOrder, inOrder, prevIndex, index+1, right);

	return root;
}

Node *Rebuild(int *prevOrder, int *inOrder, size_t prevLen, size_t inLen)
{
	assert(prevOrder && inOrder && (prevLen == inLen));
	size_t prevIndex = 0;
	return _Rebuild(prevOrder, inOrder, prevIndex, 0, inLen-1);
}

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
int main()
{
	int pOrder[] = {1, 2, 3, 4, 5, 6 };
	int iOrder[] = {3, 2, 4, 1, 6, 5};
	Node *root = Rebuild(pOrder, iOrder, 6, 6);
	prevOrder(root); //前序遍历
	return 0;
}
