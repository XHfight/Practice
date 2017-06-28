/*************************************************************************
	> File Name: LongestDistance.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 三  6/28 14:18:08 2017
 ************************************************************************/
/*
 * 有一个长为n的数组A，求满足0≤a≤b<n的A[b]-A[a]的最大值。
给定数组A及它的大小n，请返回最大差值。
 */

#include<iostream>
using namespace std;

class LongestDistance {
public:
    int getDis(vector<int> A, int n) {
        // write code here
        int maxSub = -1;
        for(int i = 0; i< n; ++i)
        {
            for(int j = i; j < n; ++j)
            {
                int sub = A[j]-A[i];
                if(sub > maxSub)
                    maxSub = sub;
            }
        }
        return maxSub;
    }
};
