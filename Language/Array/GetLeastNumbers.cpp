/*************************************************************************
	> File Name: GetLeastNumbers.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Fri 02 Jun 2017 10:55:48 PM CST
 ************************************************************************/

/* 输入n个整数，找出其中最小的K个数。
 * 例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
 */
#include<iostream>
#include<vector>
using namespace std;

//思路1：采用快排的partation函数，分出k左右的数字。
int Partation(vector<int> &arr, int begin, int end)
{
	int key = arr[end];
	while(begin < end)
	{
		while(begin < end && arr[begin]<=key)
			++begin;
		arr[end] = arr[begin];
		while(begin < end && arr[end]>=key)
			--end;
		arr[begin] = arr[end];
	}
	arr[begin] = key;
	return begin;
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k)
{
	int begin = 0;
	int end = input.size()-1;
	int index = Partation(input, begin, end);
	while(index != k-1)
	{
		if(index > k-1)
			end = index-1;
		else
			begin = index+1;
		index = Partation(input, begin, end);
	}

	vector<int> output;
	output.resize(k);
	for(int i = 0; i < k; ++i)
	{
		output[i] = input[i];
	}	
	return output;
}

int main()
{
	int arr[] = {4, 5, 1, 6, 2, 7, 3, 8};
	vector<int> input(arr, arr+sizeof(arr)/sizeof(arr[0]));
	int k;
	cin >> k;
	
	vector<int> output = GetLeastNumbers_Solution(input, k);
	vector<int>::iterator it = output.begin();
	while(it != output.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return 0;
}
