/*************************************************************************
	> File Name: AverageAge.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Sun 14 May 2017 10:07:15 PM CST
 ************************************************************************/
/*题目描述
已知某公司总人数为W，平均年龄为Y岁(每年3月末计算，同时每年3月初入职新人)，
假设每年离职率为x，x>0&&x<1,每年保持所有员工总数不变进行招聘，新员工平均年龄21岁。
从今年3月末开始，请实现一个算法，可以计算出第N年后公司员工的平均年龄。(最后结果向上取整)。 
*/
#include <iostream>
#include <math.h>
using namespace std;

//递归法
//int averageAge(double Y, double x, int N)
//{
//	if(N == 0)
//		return (int)ceil(Y);
//	else
//	{
//		//为什么用Y+1*(1-x),因为第二年平均年龄加1.
//		return averageAge(((Y+1)*(1-x)+21*x), x, N-1);
//	}
//}

//循环处理
int averageAge(double Y, double x, int N)
{
	while(N--)
	{
		Y = (Y+1)*(1-x)+21*x;
	}
	return ceil(Y);
}


int main()
{
	int W, N; 
	double Y, x;
	while(cin >> W >> Y >> x >> N)
	{
		cout << averageAge(Y,x,N) << endl;
	}
	return 0;
}
