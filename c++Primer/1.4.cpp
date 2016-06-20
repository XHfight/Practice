//1.4.1

//p10
//#include <iostream>
//
//int main()
//{
//	int sum = 0, val = 1;
//	while(val <= 10)
//	{
//		sum += val;
//		++val;
//	}
//	std::cout << "Sum of 1 to 10 inclusive is: " << sum << std::endl;
//	system("pause");
//	return 0;
//}

//练习1.9
//#include <iostream>
//
//int main()
//{
//	int sum = 0, val = 50;
//	while(val <= 100)
//	{
//		sum += val;
//		val++;
//	}
//	std::cout << "Sum of 50 to 100 inclusive is: " << sum << std::endl;
//	system("pause");
//	return 0;
//}

//练习1.10
//#include <iostream>
//
//int main()
//{
//	int num = 10;
//	while(num >= 0)
//	{
//		std::cout << num << " ";
//		num--;
//	}
//	std::cout << std::endl;
//	system("pause");
//	return 0;
//}

//练习1.11
//#include <iostream>
//
//int main()
//{
//	int num1 = 0, num2 = 0;
//	std::cout << "Enter two numbers:" <<std::endl;
//	std::cin >> num1 >> num2;
//	if(num1 >= num2)
//	{
//		while(num1 >= num2)
//		{
//			std::cout << num2 << " ";
//			num2++;
//		}
//	}
//	else
//	{
//		while(num1 <= num2)
//		{
//			std::cout << num1 << " ";
//			num1++;
//		}
//	}
//	system("pause");
//	return 0;
//}

//1.4.2

//p11
//#include <iostream>
//
//int main()
//{
//	int sum = 0;
//	for(int val = 0; val <= 10; ++val)
//	{
//		sum += val;
//	}
//	std::cout << "Sum of 1 to 10 inclusive is "
//		<< sum << std::endl;
//	system("pause");
//	return 0;
//}

//练习1.12
//完成-100到100的连加  sum最终为0
//#include <iostream>
//
//int main()
//{
//	int sum = 0;
//	for(int i = -100; i <= 100; i++)
//	{
//		sum += i;
//	}
//	std::cout << sum  <<std::endl;
//	system("pause");
//	return 0;
//}

//练习1.13
//#include <iostream>
//
//int main()
//{
//	int sum = 0;
//	for(int i = 1; i <= 10; ++i)
//	{
//		sum += i;
//	}
//	std::cout << sum <<std::endl;
//	system("pause");
//	return 0;
//}

//练习1.14
//for循环使用于已知循环次数，而while循环可用于循环次数未知的。

//练习1.15
//error C2470: “main”: 看起来像函数定义，但没有参数列表；跳过明显的函数体
//error C2143: 语法错误 : 缺少“;”(在“:”的前面)
//error C2065: “Update”: 未声明的标识符
//error C2143: 语法错误 : 缺少“;”(在“std::endl”的前面)
//error C2143: 语法错误 : 缺少“;”(在“}”的前面)
//error C2440: “初始化”: 无法从“const char [6]”转换为“int”
//error C2065: “v”: 未声明的标识符
//error C2065: “cout”: 未声明的标识符
//#include <iostream>
//
//int main()
//{
////	std::cout << "Read each file" << std::endl:
////	std::cout << Update master. << std::endl;
////	std::cout << "Write new master."std::endl; 
////	int n = "Hello";
//	int v1 = 0, v2 = 0;
////  std::cout << v << v2;
//	cout << v1+v2 <<std::endl;
//	system("pause");
//	return 0;
//}

//1.4.3

//p13
//#include <iostream>
//
//int main()
//{
//	int sum = 0, val = 0;
//	while(std::cin >> val)
//	{
//		sum += val;
//	}
//	std::cout << "Sum is:" << sum << std::endl;
//	system("pause");
//	return 0;
//}

//练习1.16
//同上

//1.4.4

//p15
//#include <iostream>
//
//int main()
//{
//	int currVal = 0, val = 0;
//
//	if(std::cin >> currVal)
//	{
//		int cnt = 1;
//		while(std::cin >> val)
//		{
//			if(val == currVal)
//			{
//				cnt++;
//			}
//			else
//			{
//				std::cout << currVal << " Occurs " << cnt << " Times " <<std::endl;
//				currVal = val;
//				cnt = 1;
//			}
//		}
//		std::cout << currVal << " Occurs " << cnt << " Times " << std::endl;
//	}
//	system("pause");
//	return 0;
//}

//练习1.17，1.18同上
//练习1.19
//#include <iostream>
//
//int main()
//{
//	int num1 = 0, num2 = 0;
//	std::cin >> num1 >> num2;
//	if(num1 < num2)
//	{
//		int tmp = num1;
//		num1 = num2;
//		num2 = tmp;
//	}
//	while(num1 >= num2)
//	{
//		std::cout << num1 << " ";
//		num1--;
//	}
//	std::cout << std::endl;
//	system("pause");
//	return 0;
//}