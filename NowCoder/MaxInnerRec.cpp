/*************************************************************************
	> File Name: MaxInnerRec.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 二  7/ 4 22:49:29 2017
 ************************************************************************/
/*题目描述：
 * 有一个直方图，用一个整数数组表示，其中每列的宽度为1，求所给直方图包含的最大矩形面积。比如，对于直方图[2,7,9,4],它所包含的最大矩形的面积为14(即[7,9]包涵的7x2的矩形)。
给定一个直方图A及它的总宽度n，请返回最大矩形面积。保证直方图宽度小于等于500。保证结果在int范围内。
 */

#include<iostream>
using namespace std;

//思路：例2，7，9，4，1
//1）第一列最大面积：比较2和2
//2）第二列最大面积：比较7和7， 7和2*2
//3）第三列最大面积：比较9和9， 9和7*2， 14和2*3
//...
//每次比较当前最大面积 和 列区间的最小值＊列数

class MaxInnerRec {
public:
    int countArea(vector<int> A, int n) {
        // write code here
        int maxArea = 0;
        int min;  //纪录当前的最小高度
        for(int i = 0; i < n; ++i)
        {
            min = INT_MAX;
            for(int j = i; j >= 0; --j)
            {
                if(A[j] < min)
                    min = A[j];

                int area = min*(i-j+1);  //列区间最小值＊列数
                if(area > maxArea)
                    maxArea = area;
            }
        }
        return maxArea;
    }
};
