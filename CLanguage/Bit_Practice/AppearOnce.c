#include <stdio.h>
#include <stdlib.h>

/*
1.��Ŀ��һ������������ֻ��һ�����ֳ�����һ�Σ��������ֶ����������Σ���д�����ҳ�������һ�ε����֡�
		�磺{1��2��1��2��3}���ҳ�1
2.��Ŀ��һ�����������������������֮�⣬���������ֶ����������Σ���д�����ҳ�������ֻ����һ�ε����֡�
		�磺{1��2��1��2��3��4}���ҳ�3��4
3.��Ŀ������һ���������飬����һ�����ֳ���1��֮�⣬��������������3�Σ����ҳ�����һ�ε�����
		�磺{1��2��1��2��1��2��7}���ҳ�7

*/

//1.
//0^a = a
//a^a = 0
//int FindAppearOnce(int arr[], int len)
//{
//	int i = 0;
//	int ret = 0;
//	for(i = 0; i<len; i++)
//	{
//		ret = arr[i]^ret;
//	}
//	return ret;
//}

//2.

//void FindAppearOnce(int arr[], int len, int* pn1, int* pn2)
//{
//	int num = 0;//��¼�������Ľ����������һ�γ��ֵ������Ľ��
//	int i = 0;
//	int k = 1;
//
//	for(i = 0; i<len; i++)  //�ó��������Ľ����������һ�γ��ֵ������Ľ��
//	{
//		num = num^arr[i];
//	}
//
//	while(num&1 != 1)    //�ҳ�������е�һ��Ϊ1��bitλ
//	{
//		k++;
//		num = num>>1;
//	}
//
//	for(i = 0; i<len ; i++)//��ԭ�����Ϊ���飬�ֱ����ÿ���г���һ�ε�����
//	{
//		int k_bit = (arr[i]>>(k-1)) & 1; //arr[i]��kλ��ֵ
//		if(k_bit == 1)
//		{
//			*pn1 = *pn1^arr[i];
//		}
//		else
//		{
//			*pn2 = *pn2^arr[i];
//		}
//	}
//
//}



int main()
{
	//1.
	/*
	int ret = 0;
	int arr[5] = {1, 2, 1, 2, 3};
	ret = FindAppearOnce(arr, sizeof(arr)/aizeof(arr[0]));
	printf("%d\n", ret);
	system("pause");
	return 0;
	*/

	//2.
	//int num1 = 0, num2 =0;
	//int arr[6] = {1, 2, 1, 2, 3, 4};
	//FindAppearOnce(arr, sizeof(arr)/sizeof(arr[0]), &num1, &num2);
	//printf("%d %d\n", num1, num2);
	//system("pause");
	//return 0;


	

}