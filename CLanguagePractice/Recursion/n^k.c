/*
��Ŀ����дһ������ʵ��n^k��ʹ�õݹ�ʵ��
*/
#include <stdio.h>

int KPower(int n, int k)  //k>=0�����
{
	if(k == 0)
	{
		return 1;
	}
	else if(k == 1)
	{
		return n;
	}
	else
	{
		return n*KPower(n, k-1);
	}
}

int main()
{
	int n = 2;
	int k = 3;

	int ret = KPower(n, k);
	printf("%d\n", ret);
	return 0;
}
