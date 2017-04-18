/*************************************************************************
	> File Name: MergeSort.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Tue 18 Apr 2017 01:50:13 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//快排
void QuickSort(int *arr, int left, int right)
{
	if(left >= right)
		return;
	int key = arr[right];  //坑在最右边
	int i = left, j = right;  //j为坑
	while(i < j)
	{
		while(i < j && arr[i] <= key)//从左边开始找大
			++i;
		arr[j] = arr[i];   //i变为坑,没找到的话相当于把自己赋给自己了。
		while(i < j && arr[j] >= key) //从右边找小
			--j;
		arr[i] = arr[j];  //j变为坑
	}
	arr[j] = key; //填坑
	QuickSort(arr, left, j-1);
	QuickSort(arr, j+1, right);
}


void Print(int *arr, size_t len)
{
	for(int i = 0; i < len; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int len = sizeof(arr)/sizeof(arr[0]);
	Print(arr, len);
	QuickSort(arr, 0, len-1);
	Print(arr, len);
	return 0;	
}
