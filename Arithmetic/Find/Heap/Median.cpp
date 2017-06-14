/*************************************************************************
	> File Name: Median.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 三  6/14 19:46:25 2017
 ************************************************************************/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*题目：
 * 如何得到一个数据流中的中位数？
 * 如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
 * 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
 */


//思路：借助两个堆，第一个大堆，第二个小堆
//1.大堆的所有数小于小堆；
//2.大堆的元素个数和小堆之差不能超过1；
//结果：奇数：大堆的顶端；偶数：（大堆的顶端＋小堆顶端）/2
//时间复杂度：插入O(logN)  获取中位数：O(1)
bool Compare(int num1, int num2)
{
	if(num1 > num2)
		return true;
	else
		return false;
}

class Solution {
public:
    void Insert(int num)
    {
		if(size%2 == 0) //偶数
		{
			if(!min_heap.empty() && num > min_heap[0])
			{
				min_heap.push_back(num);
				push_heap(min_heap.begin(), min_heap.end(), Compare);
				
				max_heap.push_back(min_heap[0]);
				push_heap(max_heap.begin(), max_heap.end());

				pop_heap(min_heap.begin(), min_heap.end(), Compare);
				min_heap.pop_back();
			}
			else
			{
				max_heap.push_back(num);
				push_heap(max_heap.begin(), max_heap.end());
			}
		}
		else  //奇数
		{
			if(num < max_heap[0]) //num小于大堆最大值。
			{
				//插入大堆，将大堆最大值移入小堆。
				max_heap.push_back(num);
				push_heap(max_heap.begin(), max_heap.end());

				min_heap.push_back(max_heap[0]);
				push_heap(min_heap.begin(), min_heap.end(), Compare);
				
				pop_heap(max_heap.begin(), max_heap.end());
				max_heap.pop_back();
			}
			else  //直接插入小堆
			{
				min_heap.push_back(num);
				push_heap(min_heap.begin(), min_heap.end(), Compare);
			}
		}
		++size;
    }

    double GetMedian()
    {
		if(size%2 == 0)
			return (min_heap[0]+max_heap[0])/2.0;
		else
			return max_heap[0];
    }
private:
	vector<int> max_heap;
	vector<int> min_heap;
	int size;
};

int main()
{
	return 0;
}
