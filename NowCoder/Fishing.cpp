/*************************************************************************
	> File Name: Fishing.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 五  6/30 23:31:31 2017
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int n,m,x,y,t;
    while(cin >> n >> m >> x >> y >> t)
	{
		if(n <=0 || m <=0 || x<=0 || x>n || y <=0 || y>m || t<0 || t>1000)
	       return 0;
 	   double *matrix = new double[m*n];//第i行第j个数代表坐标为(i,j)的格子钓到鱼的概率为p(0≤p≤1);
 	   double all = 0;
 	   for(int i = 0; i < n; ++i)
 	   {
 	       for(int j = 0; j < m; ++j)
 	       {
 	       	cin >> matrix[i*m+j];    
 	   		all += matrix[i*m+j];
 	       }
 	   }
 	   
 	   //至少钓到一条鱼的概率情况比较多，所以用对立事件，即1-P(一条鱼都钓不到)
 	   double cc = 1 - pow(1-matrix[(x-1)*m+(y-1)], t);
 	   double ss =  1 - pow(1-(all/(m*n)), t);
 	   if(cc > ss)
 	   {
 	       cout << "cc" << endl;
 	       printf("%.2f\n", cc);
 	   }
 	   else if(ss > cc)
 	   {
 	       cout << "ss" << endl;
 	       printf("%.2f\n", ss);
 	   }
 	   else
 	   {
 	       cout << "equal" <<endl;
 	       printf("%.2f\n", ss);
 	   }
	}
    return 0;
}
