/*************************************************************************
	> File Name: ChinaBull.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Fri 19 May 2017 10:38:13 AM CST
 ************************************************************************/
/*题目:
风口之下，猪都能飞。当今中国股市牛市，真可谓“错过等七年”。 给你一个回顾历史的机会，已知一支股票连续n天的价格走势，以长度为n的整数数组表示，数组中第i个元素（prices[i]）代表该股票第i天的股价。 假设你一开始没有股票，但有至多两次买入1股而后卖出1股的机会，并且买入前一定要先保证手上没有股票。若两次交易机会都放弃，收益为0。 设计算法，计算你能获得的最大收益。 输入数值范围：2<=n<=100,0<=prices[i]<=100 
*/
#include<iostream>
#include<vector>
#include<limits.h>
#include<sstream>
using namespace std;
//解题思路：
//将问题按天分解，用四个变量分别记录截至这天的第一次买入的最高收益，第一次卖出的最高收益，第二次买入的最高收益，第二次卖出的最高收益，循环n填就是，就是n天后的最高收益。

int calculateMax(const vector<int>& prices)
{
	int firBuy = INT_MIN, firSale = 0;
	int secBuy = INT_MIN, secSale = 0;

	for(int i = 0; i < prices.size(); ++i)
	{
		firBuy = (firBuy > -prices[i]) ? firBuy : -prices[i];
		firSale = (firSale > (firBuy+prices[i])) ? firSale : (firBuy+prices[i]);
		secBuy = (secBuy > (firSale-prices[i])) ? secBuy : (firSale-prices[i]);
		secSale = (secSale > (secBuy+prices[i])) ? secSale : (secBuy+prices[i]);
	}
	return secSale;
}

int main()
{
	vector<int> prices;
	int i;
	prices.push_back(3);
	prices.push_back(8);
	prices.push_back(5);
	prices.push_back(1);
	prices.push_back(7);
	prices.push_back(8);
	cout << calculateMax(prices) << endl;
	return 0;
}
