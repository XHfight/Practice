/*
��������
�����Ӽ�������һ��������8λ������ʮ���������ַ���������ת��Ϊ����ʮ�������������
����ע��ʮ���������е�10~15�ֱ��ô�д��Ӣ����ĸA��B��C��D��E��F��ʾ��
��������
FFFF
�������
65535
*/

#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	string src;
	cin >> src;
	int i = src.length()-1;
	long long dst = 0;
	int j = 0;
	while(i >= 0)
	{
		
		if(src[i] >= 'A' && src[i] <= 'F')
		{
			dst += pow(16, j) * ( 10 + src[i]- 'A');	
		}
		else
		{
			dst += pow(16, j) * (src[i]-'0');	
		}
		++j;
		--i;
	}
	cout << dst << endl;
	return 0;	
} 
