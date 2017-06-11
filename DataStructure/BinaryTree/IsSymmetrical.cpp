/*************************************************************************
	> File Name: IsSymmetrical.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 一  6/12 00:21:15 2017
 ************************************************************************/

#include<iostream>
using namespace std;

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/

//思路：
//对比前序遍历（根左右）和对称前序遍历（根右左).
//包括空节点也要对比，因为有可能出现所有结点都相同，但是节点数目不同的情况。
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
		if(pRoot == NULL)
			return true;
		return _isSymmetrical(pRoot->left, pRoot->right);
    }
	
	bool _isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if(pRoot1==NULL && pRoot2==NULL)
			return true;
		if(pRoot1==NULL || pRoot2==NULL)
			return false;
		if(pRoot1->val != pRoot2->val)
			return false;
		return _isSymmetrical(pRoot1->left, pRoot2->right) && \
			_isSymmetrical(pRoot1->right, pRoot2->left);
	}
};

