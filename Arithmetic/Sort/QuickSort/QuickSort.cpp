/*************************************************************************
	> File Name: MergeSort.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Tue 18 Apr 2017 01:50:13 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void InsertSort(int *arr, int len)
{
	int i = 1;
	int tmp; //保存要插入的值
	for( ; i < len; ++i)
	{
		tmp = arr[i];
		int j = i-1;
		while(j >= 0 && arr[j] > tmp)
		{
			arr[j+1] = arr[j];
			--j;
		}
		arr[j+1] = tmp;
	}
}

//优化一：三数取中法
size_t GetMid(int *arr, size_t left, size_t right)
{
	int mid = left + ((right-left)>>2);
	if(arr[left] < arr[mid])
	{
		if(arr[right] < arr[left])
			return left;
		else
		{
			if(arr[right] < arr[mid])
				return right;
			else
				return mid;
		}
	}
	else  //left >= mid
	{
		if(arr[right] < arr[mid])
			return mid;
		else//right >= mid
		{
			if(arr[right] < arr[left])
				return right;
			else
				return left;
		}
	}
}
//快排
int Partition(int *arr, int left, int right)
{
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
	return j;
}

void QuickSort(int* arr, int left, int right)
{
	if(left >= right)
		return;
	if(right-left+1 >= 13) //优化二：区间元素数量大于等于13，采用快排
	{
		int j = Partition(arr, left, right);
		QuickSort(arr, left, j-1);
		QuickSort(arr, j+1, right);
	}
	else  //<13，采用直接插入
	{
		InsertSort(arr, right+1);
	}
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
	int arr[15] = {9, 8, 13, 7, 14, 6, 10, 11, 5, 12, 4, 3, 2, 1, 0};
	int len = sizeof(arr)/sizeof(arr[0]);
	Print(arr, len);
	QuickSort(arr, 0, len-1);
	Print(arr, len);
	return 0;	
}
