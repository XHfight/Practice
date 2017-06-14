/*************************************************************************
	> File Name: KthNode.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 三  6/14 12:03:52 2017
 ************************************************************************/
/*题目：
 * 给定一颗二叉搜索树，请找出其中的第k大的结点。
 * 例如， 5 / \ 3 7 /\ /\ 2 4 6 8 中，按结点数值大小顺序第三个结点的值为4。
 */

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
		if(k <= 0 || pRoot == NULL)
			return NULL;
		return _KthNode(pRoot, k);  
    }

	TreeNode* _KthNode(TreeNode* pRoot, int &k)
	{
		TreeNode* ret = NULL;
		if(ret==NULL && pRoot->left)
			ret =  _KthNode(pRoot->left, k);

		if(k == 1)
			ret = pRoot;
		--k;
		
		if(ret==NULL && pRoot->right)
			ret = _KthNode(pRoot->right, k);
		return ret;
	}
    
};

int main()
{
	return 0;
}
