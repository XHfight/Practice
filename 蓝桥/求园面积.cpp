/*
设圆半径r，圆柱高h 求圆周长C1、圆面积Sa、圆球表面积Sb、圆球体积Va、圆柱体积Vb。 
用scanf输入数据，输出计算结果，输出时要求文字说明，取小数点后两位数字。请编程序。 PI＝3.14
*/ 

#include <iostream>
using namespace std;
#define PI 3.14

int main()
{
	float r = 0.0; //半径
	float h = 0.0; //高度

	cin >> r >> h;
	
	float C1 = 2*PI*r; //周长
	float Sa = r*r*PI; //面积
	float Sb = 4*PI*r*r;//圆球表面积
	float Va = (4*PI*r*r*r)/3; //圆球体积
	float Vb = r*r*h*PI;//圆柱体积 
	printf("C1=%2.2f\n", C1);
	printf("Sa=%2.2f\n", Sa);	
	printf("Sb=%2.2f\n", Sb);
	printf("Va=%2.2f\n", Va);
	printf("Vb=%2.2f\n", Vb);

	return 0;
}
