/*
从上到下按层打印二叉树。每一层打印一行。
*/


//思路：利用栈纪录当前行和下一行节点数目，如果当前行数目变为0，就打印换行，并将下一行的数目给当前行，下一行置0；
#include <iostream>
#include <assert.h>
#include <queue>
using namespace std;

struct BinaryTreeNode
{
	int val;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
}Node;

void Print(Node *root)
{
	assert(root);
	int curNum = 1; //当前行节点的数目
	int nextNum = 0; //下一行节点的数目
	queue<Node*> nodes;
	nodes.push(root);
	while(!nodes.empty())
	{
		Node *cur = nodes.front();
		if(cur->left)
		{
			nodes.push(cur->left);
			++nextNum;
		}
		if(cur->right)
		{
			nodes.push(cur->right);
			++nextNum;
		}
		
		nodes.pop();
		cout << cur->val << " ";
		--curNum;
		
		if(curNum == 0)
		{
			cout << endl;
			curNum = nextNum;
			nextNUm = 0;
		}
	}
}

int main()
{
	return 0;
}
