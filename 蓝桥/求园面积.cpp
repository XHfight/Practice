/*
��Բ�뾶r��Բ����h ��Բ�ܳ�C1��Բ���Sa��Բ������Sb��Բ�����Va��Բ�����Vb�� 
��scanf�������ݣ���������������ʱҪ������˵����ȡС�������λ���֡������� PI��3.14
*/ 

#include <iostream>
using namespace std;
#define PI 3.14

int main()
{
	float r = 0.0; //�뾶
	float h = 0.0; //�߶�

	cin >> r >> h;
	
	float C1 = 2*PI*r; //�ܳ�
	float Sa = r*r*PI; //���
	float Sb = 4*PI*r*r;//Բ������
	float Va = (4*PI*r*r*r)/3; //Բ�����
	float Vb = r*r*h*PI;//Բ����� 
	printf("C1=%2.2f\n", C1);
	printf("Sa=%2.2f\n", Sa);	
	printf("Sb=%2.2f\n", Sb);
	printf("Va=%2.2f\n", Va);
	printf("Vb=%2.2f\n", Vb);

	return 0;
}
