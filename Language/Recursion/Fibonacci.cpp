/*************************************************************************
	> File Name: Fibonacci.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Wed 04 Jan 2017 05:48:32 PM CST
 ************************************************************************/
/*
 * 大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项。
 * n<=39
 */

#include<iostream>
using namespace std;

class Solution {
	public:
    int Fibonacci(int n) {
		int fib[39];
        fib[0] = 0;
        fib[1] = 1;
								        
		 if(n < 0){
		      return -1;
	     }else if(n == 0 || n == 1){
		      return fib[n];
	     }else{
			 for(int i = 2; i <= n; ++i){
				 fib[i] = fib[i-1]+fib[i-2];
		       }
		 return fib[n];
		}        
	}
};

int main()
{
	Solution s;
	cout << s.Fibonacci(4) << endl;
	return 0;
}
