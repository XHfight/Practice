/*************************************************************************
	> File Name: HouseRobber.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 二  9/ 5 09:14:45 2017
 ************************************************************************/

/*抢房子：
 * 问题：每个房子里有钱，不能抢相邻的房子，求能抢到的最大钱数。
 */
#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int calc(vector<int> &nums, vector<int> &tmp, int index)
    {
        if(index < 0)
            return 0;

        if(tmp[index] > -1)
            return tmp[index];
        
        if(index == 0)
        {
            tmp[index] = nums[index];
            return tmp[index];
        }
            
        int noRobCur = calc(nums, tmp, index-1);
        int robCur = nums[index] + calc(nums, tmp, index-2);
        tmp[index] = noRobCur>robCur ? noRobCur : robCur;
        return tmp[index];
    }
    
    int rob(vector<int>& nums) {
        vector<int> tmp;
        tmp.resize(nums.size());
        fill(tmp.begin(), tmp.end(), -1);
        return calc(nums, tmp, nums.size()-1);
    }
};
