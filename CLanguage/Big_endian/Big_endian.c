#include <stdio.h>
//���ģʽ��Big_endian��:�����ݵĸ��ֽڴ洢�ڵ͵�ַ�У����ֽڴ洢�ڸߵ�ַ�С�
//С��ģʽ��Little_endian��:�����ݵĸ��ֽڴ洢�ڸߵ�ַ�У����ֽڴ洢�ڵ͵�ַ�С�

//��дһ�����򣬼������Ǵ��ģʽ����С��ģʽ��

//����1
//int CheckLittle_endian()
//{
//	int i = 1;
//	char *p = (char *)&i;
//	if(*p == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}

//����2
int CheckLittle_endian()
{
	union check
	{
		int i;
		char a;
	}c;
	c.i = 1;
	if(c.a == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	if(CheckLittle_endian())
	{
		printf("С��ģʽ\n");
	}
	else
	{
		printf("���ģʽ\n");
	}
	return 0;
}