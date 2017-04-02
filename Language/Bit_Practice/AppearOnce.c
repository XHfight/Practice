#include <stdio.h>
#include <stdlib.h>

/*
1.题目：一个整型数组里只有一个数字出现了一次，其余数字都出现了两次，请写程序找出出现了一次的数字。
		如：{1，2，1，2，3}，找出1
2.题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次，请写程序找出这两个只出现一次的数字。
		如：{1，2，1，2，3，4}，找出3和4
3.题目：给定一个整型数组，除了一个数字出现1次之外，其余数都出现了3次，请找出出现一次的数。
		如：{1，2，1，2，1，2，7}，找出7

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
//	int num = 0;//记录整组异或的结果，即两个一次出现的数异或的结果
//	int i = 0;
//	int k = 1;
//
//	for(i = 0; i<len; i++)  //得出整组异或的结果，即两个一次出现的数异或的结果
//	{
//		num = num^arr[i];
//	}
//
//	while(num&1 != 1)    //找出异或结果中第一个为1的bit位
//	{
//		k++;
//		num = num>>1;
//	}
//
//	for(i = 0; i<len ; i++)//将原数组分为两组，分别求出每组中出现一次的数字
//	{
//		int k_bit = (arr[i]>>(k-1)) & 1; //arr[i]第k位的值
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