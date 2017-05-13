/*************************************************************************
	> File Name: CountArea.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Sun 14 May 2017 12:09:22 AM CST
 ************************************************************************/
/*题目描述
有一个直方图，用一个整数数组表示，其中每列的宽度为1，求所给直方图包含的最大矩形面积i。
比如，对于直方图[2,7,9,4],它所包含的最大矩形的面积为14(即[7,9]包涵的7x2的矩形)。
给定一个直方图A及它的总宽度n，请返回最大矩形面积。保证直方图宽度小于等于500。保证结果在int范围内。
*/
#include<iostream>
#include<vector>
using namespace std;

int countArea(vector<int> A, int n) {
	int* min = new int[n]; //记录i~n最小值
	int max = 0;
	for(int i = 0; i < n; ++i)
	{
		for(int j = i; j < n; ++j)
		{
			if(i == j)
			{
				min[j] = A[i];
				max = (max>A[j]) ? max : A[j];
				continue;
			}
			min[i] = (min[i]<A[j]) ? min[i] : A[j];
			max = max>min[i]*(j-i+1) ? max : min[i]*(j-i+1);
		}
	}
	return max;
}

int main()
{
	int arr[5] = {2,7,9,4,1};
	vector<int> A(arr, arr+5);
	cout << countArea(A, 5) << endl;
	return 0;
}


