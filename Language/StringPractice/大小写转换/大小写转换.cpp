/*
��Ŀ��
��дһ����������һ���ַ��������Ȳ�����20����Ȼ�������ַ����ڵ�ÿһ���ַ����д�Сд�任��������д��ĸ���Сд��Сд��ĸ��ɴ�д��Ȼ�������µ��ַ��������
���������ʽ������һ���ַ�������������ַ�������ֻ����Ӣ����ĸ���������������͵��ַ���Ҳû�пո�
���������ʽ���������ת������ַ�����
*/

#include <iostream>
#include <string>
using namespace std;
void TransformStr(string &str)
{
	int len = str.length();
	for(int i = 0; i < len; ++i)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i]-('a'-'A');
		else
			str[i] = str[i]+('a'-'A');
	}
}

int main()
{
	string str;
	cin >> str;
	TransformStr(str);
	cout << str << endl;
	return 0;
}