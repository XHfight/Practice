/*************************************************************************
	> File Name: SortArr.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 三  8/ 9 20:43:23 2017
 ************************************************************************/

#include<iostream>
#include<cassert>
using namespace std;

// 采用计数排序：
// 采用哈希的思想。用一个数组记录每个元素的出现次数，数组下标为元素值，按下标顺序和个数依次输出
// 用于小范围整数排序。
// int a[] = {12,13,12,13,19,18,15,12,15,16,17}，要求对数组a进行排序，要求时间复杂度为O(N) 
void SortArr(int *arr, size_t len)
{
	assert(arr);
	int min = arr[0];
	int max = arr[0];
	for(size_t i = 1; i < len; ++i )
	{
		if(arr[i] > max)
			max = arr[i];
		if(arr[i] < min)
			min = arr[i];
	}

	int *tmp = new int[max-min+1];
	memset(tmp, 0, sizeof(int)*(max-min+1));

	for(size_t i = 0; i < len; ++i)
	{
		tmp[arr[i]-min]++;
	}

	size_t index = 0;
	for(size_t i = 0; i < (max-min+1); ++i)
	{
		while(tmp[i]>0)
		{
			arr[index++] = i+min;
			tmp[i]--;
		}
	}
}

void PrintArr(int *arr, size_t len)
{
	for(size_t i =0; i < len; ++i)
		cout << arr[i] << " ";
	cout << endl;
}
int main()
{
	int a[] = {12,13,12,13,19,18,15,12,15,16,17};
	SortArr(a, sizeof(a)/sizeof(a[0]));
	PrintArr(a, sizeof(a)/sizeof(a[0]));
	return 0;
}
