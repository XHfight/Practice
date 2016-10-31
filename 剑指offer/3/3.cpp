/*************************************************************************
	> File Name: 3.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Sat 29 Oct 2016 04:21:47 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
/*
 *题目:在一个二维数组中，每一行都按照从左到右递增的顺序排序。每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
 */

bool Find(int* arr, int row, int col, int find)
{
	if(arr == NULL || row<0 || col<0)
		return false;
	
	int i = 0;
	int j = col-1;

	while(i<row && j>=0)
	{
		int index = i*col+j;
		if(find == arr[index])
		{
			return true;
		}
		else if(find < arr[index])
			--j;
		else
			++i;
	}
	return false;
}

int main()
{
	int arr[][4] = {
		{1,2,8,9},
		{2,4,9,12},
		{4,7,10,13},
		{6,8,11,15}};
	int find = 0;
	cin >> find;
	cout << "存在？"<<Find((int*)arr, 4, 4, find)<<endl;
	return 0;
}
