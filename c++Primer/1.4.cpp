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

//Á·Ï°1.9
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

//Á·Ï°1.10
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

//Á·Ï°1.11
#include <iostream>

int main()
{
	int num1 = 0, num2 = 0;
	std::cout << "Enter two numbers:" <<std::endl;
	std::cin >> num1 >> num2;
	if(num1 >= num2)
	{
		while(num1 >= num2)
		{
			std::cout << num2 << " ";
			num2++;
		}
	}
	else
	{
		while(num1 <= num2)
		{
			std::cout << num1 << " ";
			num1++;
		}
	}
	system("pause");
	return 0;
}