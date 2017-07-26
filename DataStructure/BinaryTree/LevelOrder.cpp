/*************************************************************************
	> File Name: LevelOrder.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 六  7/22 09:12:01 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//层序遍历二叉树

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> ret;
        if(root == NULL)
            return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* f = q.front();
            ret.push_back(f->val);
            q.pop();
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
        }
        return ret;
    }
};
