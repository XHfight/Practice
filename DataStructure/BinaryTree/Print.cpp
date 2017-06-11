/*题目:
 * 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
 */

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

//思路：
//利用两个栈
vector<vector<int> > Print(TreeNode* pRoot) {
	    vector<vector<int> > ret;
		if(pRoot == NULL)
			return ret;
		ret.resize(1);

		int rows = 1; //纪录当前行数
		stack<TreeNode*> nodes[2];
		int cur = 0; //当前行的栈
		int next = 1; //下一行的栈
		nodes[cur].push(pRoot);
		while(!nodes[cur].empty() || !nodes[next].empty())
		{
			TreeNode* curNode = nodes[cur].top();
			if(rows % 2 != 0)  //当前行为奇数行，先压左后压右,这样就下一行先出右后出左
			{
				if(curNode->left)
					nodes[next].push(curNode->left);
				if(curNode->right)
					nodes[next].push(curNode->right);
			}
			else
			{
				if(curNode->right)
					nodes[next].push(curNode->right);
				if(curNode->left)
					nodes[next].push(curNode->left);
			}


			ret[rows-1].push_back(curNode->val); 
			cout << curNode->val << " ";
			nodes[cur].pop();
			if(nodes[cur].empty())
			{
				cout << endl;
				swap(cur, next);
				++rows;
				if(!nodes[cur].empty())
					ret.resize(ret.size()+1);
			}
		}
		return ret;
}


int main()
{

	TreeNode* root;
	root = new TreeNode(8);
	root->left = new TreeNode(6);
	root->right = new TreeNode(10);
	TreeNode* l=root->left;
	TreeNode* r = root->right;
	l->left = new TreeNode(5);
	l->right = new TreeNode(7);
	r->left = new TreeNode(9);
	r->right = new TreeNode(11);
	vector<vector<int> > ret = Print(root);

	for(int i = 0; i < ret.size(); ++i)
	{
		for(int j = 0 ; j < ret[i].size(); ++j)
			cout << ret[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	return 0;
}
