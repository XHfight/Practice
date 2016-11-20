#include <iostream>
using namespace std;

int main()
{
	string str;
	cin >> str;
	int i = 0;
	int size = str.size();
	for(; i<size; ++i)
	{
		str[i] = str[i]+4;
	}
	cout << str << endl;
	return 0;
 } 
