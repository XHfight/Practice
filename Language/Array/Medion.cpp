/*************************************************************************
	> File Name: Medion.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 三  8/ 9 21:11:38 2017
 ************************************************************************/

#include<iostream>
#include<cassert>
using namespace std;
//求一个无序数组的中位数。

int _Partation(int *arr, int left, int right)
{
	int findMin = left-1;
	int cur = left-1;
	int key = right;
	while(findMin < right)
	{
		while(findMin < right && arr[++findMin]>=arr[key]);
		swap(arr[++cur], arr[findMin]);
	}
	return cur;
}

int Median(int *arr, int len)
{
	assert(arr);
	int midIndex = (len-1)/2;
	int mid = _Partation(arr, 0, len-1);
	while(mid != midIndex)
	{
		if(midIndex > mid)
			mid = _Partation(arr, mid+1, len-1);
		else
			mid = _Partation(arr, 0, mid-1);
	}
	return arr[midIndex];
}

int main()
{
	int arr[] = {2,5,4,9,3,6,8,7,1};
	cout << Median(arr, sizeof(arr)/sizeof(arr[0])) << endl;
	return 0;
}
