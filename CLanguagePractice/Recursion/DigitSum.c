#include <stdio.h>

/*
��Ŀ��дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮�͡�
���磬����DigitSum(1729)����Ӧ�÷���1+7+2+9�����ĺ���19��
*/
int DigitNum(int num)
{
	int sum = 0;
	if(num/10 == 0)  //numֻ��һλ�����
	{
		sum = num;
		return sum;
	}
	else
	{
		sum = (num%10) + DigitNum(num/10);
	}

	return sum;
}

int main()
{ 

	int ret = DigitNum(1729);
	printf("%d\n", ret);
	return 0;
}
