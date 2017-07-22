/*************************************************************************
	> File Name: PopOrderLegal.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 六  7/22 08:19:12 2017
 ************************************************************************/

#include<iostream>
#include<stack>
#include<cassert>
using namespace std;

//元素出栈、入栈顺序的合法性。如：入栈的序列（1,2,3,4,5），出栈序列为（4,5,3,2,1），则合法。入栈的序列（1,2,3,4,5），出栈序列为（4,5,2,3,1），则不合法。

//思路：
//1.如果出入栈序列长度不相等，则不合法
//2.同时遍历出栈入栈序列，如果不相等就push，入栈序列后移一位，如果相等，两个都后移一位。
//当入栈序列遍历完后出栈序列开始与栈顶元素比较，如果相等则pop，不相等就不合法。

bool IsLegal(int *input, int *output, size_t len_in, size_t len_out)
{
	assert(input && output && len_in>=0 && len_out>=0);
	if(len_in != len_out)
		return false;
	stack<int> s;
	size_t i = 0;  //input下标
	size_t j = 0;  //output下标
	while(i < len_in)
	{
		if(input[i] == output[j])
		{
			++i;
			++j;
		}
		else
		{
			s.push(input[i]);
			++i;
		}
	}
	while(j < len_out)
	{
		if(output[j] == s.top())
		{
			s.pop();
			++j;
		}
		else
			return false;
	}
	return true;
}

int main()
{

	int stack_in[] = { 1, 2, 3, 4, 5 };       //入栈序列  
//    int stack_out[] = { 4, 5, 3, 2, 1 };      //出栈序列  
    int stack_out[] = { 4, 5, 2, 3, 1 };      //出栈序列  
    size_t len_in = sizeof(stack_in) / sizeof(stack_in[0]);      //入栈序列长度  
    size_t len_out = sizeof(stack_out) / sizeof(stack_out[0]);   //出栈序列长度  
	cout << IsLegal(stack_in, stack_out, len_in, len_out) << endl;
	return 0;
}
