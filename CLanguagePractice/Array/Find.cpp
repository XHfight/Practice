/*
题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

#include <stdio.h>
#include <stdlib.h>

#define ROW 4
#define COL 4

bool Find(int* arr,int row,int col,int num)
{
	int _row = 0;
	int _col = col-1;
	if(arr == NULL)
	{
		return false;
	}
	while(_row <= row-1 && _col >= 0)
	{
		if(num == arr[_row*col+_col])
		{
			return true;
		}
		else if(num > arr[_row*col+_col])
		{
			_row++;
		}
		else
		{
			_col--;
		}
	}
	return false;
}
int main()
{
	int array[ROW][COL] = {{1, 2, 8, 9},
		                   {2, 4, 9,12},
	                       {4, 7,10,13},
	                       {6, 8,11,15}};
	//int findnum = 7;
	//int findnum = 15;
	//int findnum = 1;
	int findnum = 20;


	if(Find((int*)array, ROW, COL,findnum))
	{
		printf("exist\n");
	}
	else
	{
		printf("no exist!\n");
	}
	system("pause");
	return 0;
}