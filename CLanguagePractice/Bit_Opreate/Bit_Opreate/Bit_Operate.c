#include <math.h>

//1.���ʵ�֣�
//����int��32λ������m��n�Ķ����Ʊ���У��ж��ٸ�λ(bit)��ͬ�� 
//��������:
//1999 2299
//�������:7

int bit_diff(int num1, int num2)
{
	int num = 0;
	int count = 0;
	num = num1^num2;
	while(num)
	{
		num = num & (num-1);
		count++;
	}
	return count;
}


//2.��д������
//unsigned int  reverse_bit(unsigned int value);
//��������ķ��� ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//          2550136832

//����1
//unsigned int reverse_bit(unsigned int value)
//{
//	unsigned int reverse = 0;
//	int i = 0;
//	for(; i<32; ++i)
//	{
//		reverse += (unsigned int)(value&1)*pow(2, 31-i);
//		value >>= 1;
//	}
//	return (unsigned int)reverse;
//}

//������
unsigned int reverse_bit(unsigned int value)
{
	unsigned int reverse = 0;
	int i = 0;
	for(i = 0; i<32; ++i)
	{
		reverse <<= 1;
		reverse |= ((value>>i)&1);
	}
	return (unsigned int)reverse;
}


