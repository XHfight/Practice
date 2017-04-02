 /*
 下面给出了杨辉三角形的前4行：
　　
1
　　
1 1
　　
1 2 1
　　
1 3 3 1
　　
给出n，输出它的前n行。
输入格式
输入包含一个数n。
输出格式
输出杨辉三角形的前n行。每一行从这一行的第一个数开始依次输出，中间使用一个空格分隔。请不要在前面输出多余的空格。 
*/

#include <iostream>
using namespace std;

int main()
{
	int n; //行数 
	cin >> n;
	
	int* arr= new int[n*n];
	int i = 0;
	int j = 0;
	for( ; i < n; ++i)
	{
		for(j = 0 ; j <= i; ++j)
		{
			if(j==0 || j==i)
				arr[i*n+j] = 1;
			else
				arr[i*n+j] = arr[(i-1)*n+j-1] + arr[(i-1)*n + j];
			cout << arr[i*n+j] << " ";
		} 
		cout << endl;
	}
	return 0;	
} 
