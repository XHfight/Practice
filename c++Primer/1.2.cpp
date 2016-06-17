//P5
 
//#include <iostream>
//
//int main()
//{
//	std::cout << "Enter two numbers:" << std::endl;
//	int v1 = 0, v2 = 0;
//	std::cin >> v1 >> v2;
//	std::cout << "The sum of:" << v1 << " and " << v2
//		<< " is " << v1+v2 << std::endl;
//	system("pause");
//	return 0;
//}

//练习1.3
//#include <iostream>
//
//int main()
//{
//	std::cout << "Hello,World。" << std::endl;
//	system("pause");
//	return 0;
//}

//练习1.4
//#include <iostream>
//
//int main()
//{
//	int num1 = 0, num2 = 0;
//	std::cout << "Enter two numbers:" << std::endl;
//	std::cin >> num1 >> num2;
//	std::cout << "The multiply is:" << num1*num2 << std::endl;
//	system("pause");
//	return 0;
//}

//练习1.5
//#include <iostream>
//
//int main()
//{
//	int v1 = 1, v2 = 2;
//	std::cout << "The sum of: " << v1 << " and " << v2
//		<< " is " << v1+v2 << std::endl;
//	std::cout << "The sum of: ";
//	std::cout << v1;
//	std::cout << " and ";
//	std::cout << v2;
//	std::cout << " is ";
//	std::cout << v1+v2;
//	std::cout << std::endl;
//	system("pause");
//	return 0;
//}

//练习1.6
//不合法。因为；代表语句结束，下面两行语句<<没有左值。
//	修改：1.将第一行和第二行的分号去掉；
//		  2.将第二和第三行加上std::cout。
//#include <iostream>
//
//int main()
//{
//	int v1 = 1, v2 = 2;
//	std::cout << "The sum of: " << v1
//				<< " and " << v2
//				<< " is " << v1+v2 << std::endl;
//	system("pause");
//	return 0;
//}