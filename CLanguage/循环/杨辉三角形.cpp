 /*
 �����������������ε�ǰ4�У�
����
1
����
1 1
����
1 2 1
����
1 3 3 1
����
����n���������ǰn�С�
�����ʽ
�������һ����n��
�����ʽ
�����������ε�ǰn�С�ÿһ�д���һ�еĵ�һ������ʼ����������м�ʹ��һ���ո�ָ����벻Ҫ��ǰ���������Ŀո� 
*/

#include <iostream>
using namespace std;

int main()
{
	int n; //���� 
	cin >> n;
	
	int* arr= new int[n*n];
	int i = 0;
	int j = 0;
	for( ; i < n; ++i)
	{
		for(j = 0 ; j <= i; ++j)
		{
			if(j==0 || j==i)
				arr[i*n+j] = 1;
			else
				arr[i*n+j] = arr[(i-1)*n+j-1] + arr[(i-1)*n + j];
			cout << arr[i*n+j] << " ";
		} 
		cout << endl;
	}
	return 0;	
} 
