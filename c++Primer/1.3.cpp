//练习1.7
//1>c:\学习\code\c++\c++primer\1.3\1.3\1.3.cpp(13): warning C4138: 在注释外找到“*/”
//1>c:\学习\code\c++\c++primer\1.3\1.3\1.3.cpp(13): error C2059: 语法错误:“/”
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

//练习1.8
#include <iostream>

int main()
{
	std::cout << "/*";
	std::cout << "*/";
//	std::cout <</* "*/" */;不合法
	std::cout << /* "*/" /* "/*" */;
	system("pause");
	return 0;
}