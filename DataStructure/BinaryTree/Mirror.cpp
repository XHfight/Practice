/*************************************************************************
	> File Name: Mirror.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 四  6/15 21:03:01 2017
 ************************************************************************/

#include<iostream>
using namespace std;

/*题目：操作给定的二叉树，将其变换为源二叉树的镜像*/

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

//解题思路：
//交换每个非叶子节点的左右子树。

class Solution {
public:
    void Mirror(TreeNode *pRoot) {
		if(pRoot == NULL)
			return ;
		//交换左右子树
		TreeNode* tmp = pRoot->left;
		pRoot->left = pRoot->right;
		pRoot->right = tmp;

		Mirror(pRoot->left);
		Mirror(pRoot->right);
    }
};
