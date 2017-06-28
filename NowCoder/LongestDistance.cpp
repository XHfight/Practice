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
	//时间复杂度O(N^2)
    int getDis(vector<int> A, int n) {
        // write code here
        int maxSub = -1;
        if(n > 0)
		{
			for(int i = 0; i< n; ++i)
			{
				for(int j = i; j < n; ++j)
				{
					int sub = A[j]-A[i];
					if(sub > maxSub)
						maxSub = sub;
		        }
			 }
		}
        return maxSub;
    }

	//时间复杂度哦：O(N)
	int getDis_2(vector<int> A, int n)
	{
		int maxSub = -1;
		if(n > 0)
		{
            int min = A[0];
            int sub = -1;
			for(int i = 1; i < n; ++i)
			{
				if(A[i] < min)
					min = A[i];

				sub = A[i]-min;
				if(sub > maxSub)
					maxSub = sub;
			}
		}
		return maxSub;
	}
};
