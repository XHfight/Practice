#include <stdio.h>

/*
��Ŀ��дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�͡�
���磬����DigitSum(1729)����Ӧ�÷���1+7+2+9�����ĺ���19��
*/
int DigitNum(int num)
{
	if(num < 10)  //numֻ��һλ�����
	{
		return num;
	}
	else
	{
		return (num%10) + DigitNum(num/10);
	}
}

int main()
{ 

	int ret = DigitNum(1729);
	printf("%d\n", ret);
	return 0;
}
