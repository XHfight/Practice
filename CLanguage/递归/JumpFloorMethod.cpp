/*************************************************************************
	> File Name: JumpFloorMethod.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Wed 04 Jan 2017 06:29:46 PM CST
 ************************************************************************/
/*题目：
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 */

#include<iostream>
using namespace std;

class Solution
{
public:
	int jumpFloor(int number)
	{
		int method[100];
		method[0] = 1;
		method[1] = 1;
		if(number < 0){
			return -1;
		}else if(number == 0 || number == 1){
			return method[number];
		}else{
			for(int i = 2; i <= number; ++i){
	            method[i] = method[i-1]+method[i-2];
			}
	        return method[number];
		}
	}
};

int main()
{
	Solution jf;
	cout << jf.jumpFloor(3) << endl;

	return 0;
}
