/*************************************************************************
	> File Name: Serialize.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 二  6/13 08:55:08 2017
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;
/*题目:
 * 请实现两个函数，分别用来序列化和反序列化二叉树
 */

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
	//空节点用$表示，两节点之间用，隔开
    char* Serialize(TreeNode *root) {
		string ret;
		_Serialize(root, ret);
		return (char *)(ret.substr(0, ret.length()-1).c_str());
    }
	void _Serialize(TreeNode *root, string& str)
	{
		if(root == NULL)
		{
			str += "$,";
			return ;
		}
		
		string s = to_string(root->val);
		str += s;
		str += ',';
		_Serialize(root->left, str);
		_Serialize(root->right, str);
	}

    TreeNode* Deserialize(char *str) {
		if(str == NULL)
			return NULL;
		return _Deserialize(str);
    }

	TreeNode* _Deserialize(char* &str) //必须用str的引用或二级指针，不然的话下面两路递归走的str相同。
	{
		if(*str == '$')
		{
			str+=2;
			return NULL;
		}
		
		int val = 0;
		while(*str != '\0' && *str!=',')
		{
			val = val*10 + (*str - '0');
			++str;
		}

		TreeNode* root = new TreeNode(val);
		if(*str == '\0')
			return root;
		else 
			++str;

		root->left = _Deserialize(str);
		root->right = _Deserialize(str);	
		return root;
	}
};
