/*
��������:������ 
����1221��һ���ǳ����������������߶��ʹ��ұ߶���һ���ģ������������������λʮ��������
�����ʽ
��������С�����˳�����������������λʮ��������
*/

#include <iostream>
using namespace std;

int main()
{
	int i = 1000;
	while(i <= 9999)
	{
		int one = i%10;
		int two = i/10%10;
		int thr = i/100%10;
		int fou = i/1000%10; 
		if(one==fou && two==thr)
		{
			cout << i << endl;
		}
		i++;
	}
	return 0;
} 
