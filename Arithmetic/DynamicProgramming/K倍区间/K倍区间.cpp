/*************************************************************************
	> File Name: K倍区间.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Thu 20 Apr 2017 07:07:17 PM CST
 ************************************************************************/
/*
 *标题： k倍区间
 给定一个长度为N的数列，A1, A2, ... AN，如果其中一段连续的子序列Ai, Ai+1, ... Aj(i <= j)之和是K的倍数，我们就称这个区间[i, j]是K倍区间。  
 你能求出数列中总共有多少个K倍区间吗？  
 输入
 -----
 第一行包含两个整数N和K。(1 <= N, K <= 100000)  
 以下N行每行包含一个整数Ai。(1 <= Ai <= 100000)  
 输出
 -----
 输出一个整数，代表K倍区间的数目。  
 例如，
 输入：
 5 2
 1  
 2  
 3  
 4  
 5  
 程序应该输出：
 6
 */
#include<iostream>
using namespace std;

//思路：利用动态规划
//开辟一个临时数组，循环len次，每次统计出以i为首的k倍空间的个数。
//临时数组的每一个位置存储以i为首的当前的k倍空间的个数。
int KIntervalNums(int *arr, int len, int k)
{
	int *tmp = new int[len];
	int i = 0;
	int count = 0;
	for( ; i < len; ++i)
	{
		int sum = 0;
		for(int j = i; j < len; ++j)
		{
			sum += arr[j];
			if(sum%k == 0)
			{
				if(j == i)
					tmp[j] = 1;
				else
					tmp[j] = tmp[j-1]+1;
			}
			else
			{
				if(j == i)
					tmp[j] = 0;
				else
					tmp[j] = tmp[j-1];
			}
		}
		count += tmp[len-1];
	}
	delete[] tmp;
	return count;
}

int main()
{
	int n;
	int k;
	cin >> n >> k;
	int *arr = new int[n];
	int i = 0;
	while(i < n)
	{
		cin >> arr[i];
		++i;
	}
	cout << KIntervalNums(arr, n, k) << endl;
	return 0;
}

