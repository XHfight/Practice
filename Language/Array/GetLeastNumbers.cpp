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

//思路1：全排序，取前k O(N*logN)
//思路2：采用快排的partation函数，分出k左右的数字。O(N)
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

void QuickSort(vector<int> &arr, int begin, int end)
{
	if(begin < end)
	{
		int index = Partation(arr, begin, end);
		QuickSort(arr, begin, index-1);
		QuickSort(arr, index+1, end);
	}
}

//思路1
vector<int> GetLeastNumbers_Solution1(vector<int> &input, int k)
{
	//一定注意边界检测
	if(input.size() < k || k <= 0)
		return vector<int>();
	//排序：快排
	QuickSort(input, 0, input.size()-1);
	vector<int> output(input.begin(), input.begin()+k);
	return output;
}

//思路2
vector<int> GetLeastNumbers_Solution2(vector<int> &input, int k)
{
	if(input.size() < k || k <= 0)
		return vector<int>();
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

	vector<int> output(input.begin(), input.begin()+k);
	return output;
}

int main()
{
	int arr[] = {4, 5, 1, 6, 2, 7, 3, 8};
	vector<int> input(arr, arr+sizeof(arr)/sizeof(arr[0]));
	int k;
	cin >> k;
	
	vector<int> output = GetLeastNumbers_Solution1(input, k);
	//vector<int> output = GetLeastNumbers_Solution2(input, k);
	vector<int>::iterator it = output.begin();
	while(it != output.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return 0;
}
