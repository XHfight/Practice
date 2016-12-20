/*************************************************************************
	> File Name: ArraySort.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Sun 18 Dec 2016 08:19:22 PM CST
 ************************************************************************/

/*
 * 题目：
 *对一个数组按给定的下标进行排序，仅使用两两交换的方式。要求不能对数组进行扩容，尽可能少的开辟额外空间。
 *如：原数组为A，B，C，D，E，现给定的新位置为3，0，1，4，2，那么排序后为D，A，B，E，C。
 */

#include<iostream>
using namespace std;

//挖坑法
void Swap(char* pArr, int* pPos, int n)
{
	int pitPos = 0; //挖坑的位置
	char tmp = pArr[pitPos];   //挖坑:保存第一个位置的值	
	int i  = pitPos; //当前排序位置的下标

	while(--n)
	{
		pArr[i] = pArr[pPos[i]];
		i = pPos[i];
	}
	pArr[i] = tmp;
}

//方法二：
void Swap2(char* a, int* b, int n)
{
	for(int i = 0; i < n-1; ++i)
	{
		if(i < b[i])
		{
			swap(a[i], a[b[i]]);
		}
		else
		{
			swap(a[i], a[b[b[i]]]);
		}
		if(b[i] <= i)
		{
			b[i] = b[b[i]];
		}
	}
}
void PrintArr(char* pArr, int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << pArr[i] << " ";
	}
	cout << endl;
}

void PrintArr(int* pArr, int n)
{
	for(int i = 0; i < n; ++i)
	{
		cout << pArr[i] << " ";
	}
	cout << endl;
}

int main()
{
	char arr[] = {'A', 'B', 'C', 'D', 'E'};
	int pos[] = {3, 0, 1, 4, 2};
	//int pos[] = {2, 0, 1, 4, 3};
	cout << "arr:";
	PrintArr(arr, sizeof(arr)/sizeof(arr[0]));
	cout << "pos:";
	PrintArr(pos, sizeof(pos)/sizeof(pos[0]));

	Swap(arr, pos, sizeof(arr)/sizeof(arr[0]));
	cout << "arr:";
	PrintArr(arr, sizeof(arr)/sizeof(arr[0]));
	return 0;
}
