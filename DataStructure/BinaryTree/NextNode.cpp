/*题目：
给定义个二叉树和其中一个节点，找出中序遍历顺序的下一个节点。
*/

＃include <iostream>
using namespace std;

/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
	if(pNode == NULL)
		return NULL;
   	if(pNode->right != NULL)//右子树不为空，下一节点为右子树的最左节点。
	{
		TreeLinkNode* cur = pNode->right;
		while(cur && cur->left)
		{
			cur = cur->left;
		}
		return cur;
	}
	else //右子树为空
	{
		while(pNode->next)
		{
			TreeLinkNode* parent = pNode->next;
			if(parent->left == pNode)
			{
				return parent;
			}
			pNode = parent;
		}
		return NULL;
	}
    }
};
