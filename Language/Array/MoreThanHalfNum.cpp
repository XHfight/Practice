/*************************************************************************
	> File Name: MoreThanHalfNum.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Thu 01 Jun 2017 11:27:18 AM CST
 ************************************************************************/
/*数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
 * 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。
 */
#include<iostream>
#include<vector>
using namespace std;
//方法1：利快排的partation函数，多次调用直到找到排在最中间的数。O(N),会改变数组的内容
int Partation(vector<int> numbers, int begin, int end)
{
	int key = numbers[end];
	while(begin < end)
	{
		while(numbers[begin]<=key && begin<end)
			++begin;
		numbers[end] = numbers[begin];
		while(numbers[end]>=key && begin<end)
			--end;
		numbers[begin] = numbers[end];
	}
	//begin==end
	numbers[begin] = key;
	return begin;
}

static bool CheckMoreThanHalf(vector<int> numbers, int num)
{
	int count = 0;
	for(int i = 0; i < numbers.size(); ++i)
	{
		if(numbers[i] == num)
			++count;
	}
	if(count <= (numbers.size()>>1))
		return false;
	else
		return true;
}

int MoreThanHalfNum_Solution(vector<int> &numbers)
{
	int begin = 0;
	int end = numbers.size()-1;
	int mid = end >> 1;
	int index = Partation(numbers, begin, end);
	while(index != mid)
	{
		if(index > mid)
		{
			end = index-1;
		}
		else  //index < mid
		{
			begin = index+1;
		}
		index = Partation(numbers, begin, end);
	}
	//检查这个数是否超过一半，满足要求
	if(!CheckMoreThanHalf(numbers, numbers[index]))
		return 0;
	return numbers[index];
}

int main()
{
	int arr[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
	vector<int> array(arr, arr+sizeof(arr)/sizeof(arr[0]));
	cout << MoreThanHalfNum_Solution(array) << endl;
	return 0;
}
