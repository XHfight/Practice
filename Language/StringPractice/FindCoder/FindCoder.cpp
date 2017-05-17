/*************************************************************************
	> File Name: FindCoder.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Wed 17 May 2017 05:58:29 PM CST
 ************************************************************************/


/*题目：
 请设计一个高效算法，再给定的字符串数组中，找到包含"Coder"的字符串(不区分大小写)，并将其作为一个新的数组返回。结果字符串的顺序按照"Coder"出现的次数递减排列，若两个串中"Coder"出现的次数相同，则保持他们在原数组中的位置关系。
 给定一个字符串数组A和它的大小n，请返回结果数组。保证原数组大小小于等于300,其中每个串的长度小于等于200。同时保证一定存在包含coder的字符串。
 测试样例：
 ["i am a coder","Coder Coder","Code"],3
 返回：["Coder Coder","i am a coder"]
 */

#include<iostream>
#include<vector>
#include<string>
#include<ctype.h>
using namespace std;
int Partion(vector<int>& arr, vector<string>& A, int left, int right)
{
	int key = arr[right];
	string str = A[right];
	
	while(left < right)
	{
		while(left < right && arr[left] >= key)
			++left;
		arr[right] = arr[left];
		A[right] = A[left];
		while(left < right && arr[right] <= key)
			--right;
		arr[left] = arr[right];
		A[left] = A[right];
	}
	//这时right与left指向相同位置
	arr[right] = key;
	A[right] = str;
	return right;
}

void QuickSort(vector<int>& arr, vector<string>& A, int left, int right)
{
	if(left < right)
	{
		int mid = Partion(arr, A, left, right);
		QuickSort(arr, A, left, mid-1);
		QuickSort(arr, A, mid+1, right);
	}
}

vector<string> findCoder(vector<string>& A, int n)
{
	vector<string> ret;
	vector<int> num;
	for(int i = 0; i < n; ++i)
	{
		int count = 0;
		string str = A[i];
		for(int j = 0; j < str.length()-4; )
		{
		
			//统计字符串中coder出现的次数
			if(toupper(str[j]) == 'C' && toupper(str[j+1]) == 'O' && \
				toupper(str[j+2]) == 'D' && toupper(str[j+3]) == 'E' && \
				toupper(str[j+4]) == 'R')
			{
				++count;
				j+=5;
			}
			else
				++j;
		}
		if(count != 0)
		{
			num.push_back(count);
			ret.push_back(A[i]);
		}
	}
	//排序(快排)
	QuickSort(num, ret, 0, num.size()-1);
	vector<int>::iterator it = num.begin();
	while(it != num.end())
	{
		cout << *it << endl;
		++it;
	}
	return ret;
}

int main()
{
	vector<string> A;
	A.push_back("i am coder");
	A.push_back("coder coder");
	A.push_back("code");
	vector<string> ret = findCoder(A, 3);
	vector<string>::iterator it = ret.begin();
	while(it != ret.end())
	{
		cout << *it << endl;
		++it;
	}
	return 0;
}
