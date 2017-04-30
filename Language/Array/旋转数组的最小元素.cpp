/*************************************************************************
	> File Name: 旋转数组的最小元素.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Sun 30 Apr 2017 10:10:26 AM CST
 ************************************************************************/


//题目：
//将一个数组最开始的若干元素搬到数组的末尾，称为数组的旋转。
//例如{3, 4, 1, 2, 5}为 {1, 2, 3, 4, 5}的一个旋转。
//输入一个递增数组的旋转，输出旋转数组的最小元素。
#include <iostream>
#include <cassert>
using namespace std;

//顺序查找：时间复杂度O(N)
//思路：前面是递增的突然出现递减的那个元素就是最小值，如果一直不出现递减，则第一个元素就是最小值
int FindMin(int arr[], int len)
{
	assert(arr);
	if(len == 0)
		return 0;
	int max = arr[0];
	for(int i = 1; i < len; ++i)
	{
		if(arr[i] >= max)
			max = arr[i];
		else
			return arr[i];
	}
	return arr[0];
}

//采用二分查找的思想O(logN)
//
int FindMin2(int arr[], int len)
{
	assert(arr);
	if(len == 0)
		return 0;
	int left = 0;
	int right = len-1;
	while(right - left != 1)
	{
		int mid = left+(right-left)/2;
		if(arr[mid] >= arr[left])
			left = mid;
		else if(arr[mid] <= arr[right])
			right = mid;
	}

}

int main()
{
	int arr[5] = {3, 4, 5, 1, 2};
	int min = FindMin(arr, sizeof(arr)/sizeof(arr[0]));
	cout << min << endl;
	return 0;
}
