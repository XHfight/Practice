//��ϰ1.7
//1>c:\ѧϰ\code\c++\c++primer\1.3\1.3\1.3.cpp(13): warning C4138: ��ע�����ҵ���*/��
//1>c:\ѧϰ\code\c++\c++primer\1.3\1.3\1.3.cpp(13): error C2059: �﷨����:��/��
//#include <iostream>
//
//int main()
//{
//	/*
//	int a = 0;
//	/*
//	int b = 0;
//	*/
//	int c = 0;
//	int d = 0;
//	*/
//	system("pause");
//	return 0;
//}

//��ϰ1.8
#include <iostream>

int main()
{
	std::cout << "/*";
	std::cout << "*/";
//	std::cout <</* "*/" */;���Ϸ�
	std::cout << /* "*/" /* "/*" */;
	system("pause");
	return 0;
}