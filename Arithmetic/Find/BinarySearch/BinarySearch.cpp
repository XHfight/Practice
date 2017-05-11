/*************************************************************************
	> File Name: BinarySearch.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Thu 11 May 2017 11:04:32 PM CST
 ************************************************************************/
/*
 *对于一个有序数组，我们通常采用二分查找的方式来定位某一元素，
 *请编写二分查找的算法，在数组中查找指定元素。
 *给定一个整数数组A及它的大小n，同时给定要查找的元素val，
 *请返回它在数组中的位置(从0开始)，若不存在该元素，返回-1。若该元素出现多次，请返回第一次出现的位置。
 */
#include<iostream>
using namespace std;

/*非递归实现：
 * class BinarySearch {
 * public:
 *int getPos(vector<int> A, int n, int val) {
 *\//write code here
 *int left = 0;
 *int right = n;
 *while(left <= right)
 *{
 *	int mid = left + (right-left)/2;
 *	if(A[mid] == val)
 *		return mid;
 *  else if(val < A[mid])
 *		right = mid-1;
 *  else
 *      left = mid+1;
 * }
 * return -1;
 * }
 * };
 * /

//递归实现
int BinarySearch(int arr[], int val, int begin, int end)
{
	if(begin <= end)
	{
		int mid = begin + (end-begin)/2;
		if(arr[mid] == val)
			return mid;
		else if(arr[mid] < val)
			BinarySearch(arr, val, mid+1, end);
		else
			BinarySearch(arr, val, begin, mid-1);
	}
	else
	{
		return -1;
	}
}

int main()
{
	int arr[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
	int val = 4;
	int ret = BinarySearch(arr, val, 0, sizeof(arr)/sizeof(arr[0]));
	cout << ret << endl;
	int val2 = 5;
	int ret2 = BinarySearch(arr, val2, 0, sizeof(arr)/sizeof(arr[0]));
	cout << ret2 << endl;
	return 0;
}
