/*************************************************************************
	> File Name: MaxScore.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Mon 22 May 2017 10:05:46 PM CST
 ************************************************************************/

//题目描述
//老师想知道从某某同学当中，分数最高的是多少，现在请你编程模拟老师的询问。当然，老师有时候需要更新某位同学的成绩. 

//输入描述
/*输入包括多组测试数据。
  每组输入第一行是两个正整数N和M（0 < N <= 30000,0 < M < 5000）,分别代表学生的数目和操作的数目。
  学生ID编号从1编到N。
  第二行包含N个整数，代表这N个学生的初始成绩，其中第i个数代表ID为i的学生的成绩
  接下来又M行，每一行有一个字符C（只取‘Q’或‘U’），和两个正整数A,B,当C为'Q'的时候, 表示这是一条询问操作，他询问ID从A到B（包括A,B）的学生当中，成绩最高的是多少
  当C为‘U’的时候，表示这是一条更新操作，要求把ID为A的学生的成绩更改为B.
*/

//输出描述
//对于每一次询问操作，在一行里面输出最高成绩.
#include<iostream>
#include<vector>
using namespace std;

//本题注意：
//1.区间[A，B]，A可能比B大
//2.N，M输入多次

int getMax(vector<int>& score, size_t A, size_t B)
{
	size_t max, min;
	if(A > B)
	{
		max = A;
		min = B;
	}
	else
	{
		max = B;
		min = A;
	}

	int ret = score[min];
	for(int i = min+1; i <= max; ++i)
	{
		if(score[i] > ret)
			ret = score[i];
	}
	return ret;
}

int main()
{
	int N, M;
	while(cin >> N >> M)
	{
		vector<int> score;
		score.resize(N+1);
		int i = 0;
		for(i = 1; i <= N; ++i)
		{
			cin >> score[i];
		}
		
		char ch;
		size_t A, B;
		for(i = 0; i < M; ++i)
		{
			cin >> ch >> A >> B;
			if(ch == 'Q')
			{
				cout << getMax(score, A, B) << endl;
			}
			else if(ch == 'U')
			{
				score[A] = B;
			}
		}
	}
	return 0;
}

