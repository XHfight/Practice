/*
给出一个非负整数，将它表示成十六进制的形式。
*/ 

#include <iostream>
using namespace std;

void fun(int sum)
{
	if(sum > 0) 
	{
		fun(sum/16);
		int num = sum%16;
		switch(num)
		{
			case 10:
				cout << 'A';break;
			case 11:
				cout << 'B';break;
			case 12:
				cout << 'C';break;
			case 13:
				cout << 'D';break;
			case 14:
				cout << 'E';break;
			case 15:
				cout << 'F';break;
			default:
				cout << (char)(num+'0');break;
		}

	}				
}

int main()
{
	int n;
	cin >> n;
	if(n == 0)
		cout << n << endl;
	else
		fun(n);
	cout << endl;
	return 0;	
} 
