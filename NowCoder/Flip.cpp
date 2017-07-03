/*************************************************************************
	> File Name: Flip.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 二  7/ 4 00:59:34 2017
 ************************************************************************/

/*题目描述：
 * 在4x4的棋盘上摆满了黑白棋子，黑白两色的位置和数目随机其中左上角坐标为(1,1),右下角坐标为(4,4),现在依次有一些翻转操作，要对一些给定支点坐标为中心的上下左右四个棋子的颜色进行翻转，请计算出翻转后的棋盘颜色。
给定两个数组A和f,分别为初始棋盘和翻转位置。其中翻转位置共有3个。请返回翻转后的棋盘。
 */
#include<iostream>
using namespace std;

class Flip {
public:
    vector<vector<int> > flipChess(vector<vector<int> > A, vector<vector<int> > f) {
        // write code here
        for(int i = 0; i < f.size(); ++i)
        {
            int row = f[i][0]-1;
            int col = f[i][1]-1;
            if(row-1 < A.size() && row-1>=0)
            	A[row-1][col] = A[row-1][col]==0 ? 1 : 0;
            if(row+1 < A.size() && row+1>=0)
            	A[row+1][col] = A[row+1][col]==0 ? 1 : 0;
            if(col-1 < A[row].size() && col-1>=0)
            	A[row][col-1] = A[row][col-1]==0 ? 1 : 0;
            if(col+1 < A[row].size() && col+1>=0)
           		A[row][col+1] = A[row][col+1]==0 ? 1 : 0;
        }
        return A;
    }
};
