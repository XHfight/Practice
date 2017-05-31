/*************************************************************************
	> File Name: reOrderArray.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Wed 31 May 2017 08:34:19 PM CST
 ************************************************************************/
/*输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 * 使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组的后半部分，
 * 并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 */
#include<iostream>
#include<vector>
using namespace std;
//思路1：插入排序的思想，用两个指针控制待交换奇偶数的位置。
//思路2：空间换时间，开辟一个等大临时数组，将新顺序填入新数组。
void reOrderArray(vector<int> &array)
{
	int num = 0;
	for(int i = 0; i < array.size(); ++i)
	{
		if(array[i]%2 != 0)
			++num;
	}

	int n = 0; //记录奇数的位置
	int m = num; //记录偶数的位置
	vector<int> newArr;
	newArr.resize(array.size());
	for(int i = 0; i < newArr.size(); ++i)
	{
		if(array[i]%2 == 0) //偶数
		{
			newArr[m++] = array[i];
		}
		else //偶数
		{
			newArr[n++] = array[i];
		}
	}

	for(int i = 0; i < array.size(); ++i)
	{
		array[i] = newArr[i];
	}
}

int main()
{
	int arr[] = {2, 4, 6, 8, 1, 3, 5, 7};
	vector<int> array(arr, arr+sizeof(arr)/sizeof(arr[0]));
	reOrderArray(array);
	for(int i = 0 ; i < array.size(); ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}
