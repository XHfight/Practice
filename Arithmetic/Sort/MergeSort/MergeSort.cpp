/*************************************************************************
	> File Name: MergeSort.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Tue 18 Apr 2017 01:50:13 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;

void Merge(int *arr, int *tmp, size_t begin1, size_t begin2, size_t right)//合并两个有序的序列
{
	int i = begin1;
	size_t end1 = begin2-1;
	size_t end2 = right;
	int index = begin1; //tmp数组的下标
	//下面逻辑类似与合并两个有序单链表
	while(begin1 <= end1 && begin2 <= end2)
	{
		if(arr[begin1] < arr[begin2])
			tmp[index++] = arr[begin1++];
		else
			tmp[index++] = arr[begin2++];
	}
	
	while(begin1 <= end1)
		tmp[index++] = arr[begin1++];

	while(begin2 <= end2)
		tmp[index++] = arr[begin2++];
	
	//将tmp数组中已经合并好的数据赋值到arr数组中
	for( ; i <= right; ++i)
	{
		arr[i] = tmp[i];
	}
}

void _MergeSort(int *arr, int *tmp, size_t left, size_t right) 
{
	int mid = left+(right-left)/2;
	//一直递归进行归并排序，直到分裂为一个元素。
	if(left < right)
	{
		_MergeSort(arr, tmp, left, mid);   //分解
		_MergeSort(arr, tmp, mid+1, right);
		Merge(arr, tmp, left, mid+1, right); //合并
	}
}

void MergeSort(int *arr, size_t len)
{
	int *tmp = new int[len];
	_MergeSort(arr, tmp, 0, len-1);
	delete[] tmp;
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
	MergeSort(arr, len);
	Print(arr, len);
	return 0;	
}
