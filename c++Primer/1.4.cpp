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

//��ϰ1.9
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

//��ϰ1.10
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

//��ϰ1.11
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

//��ϰ1.12
//���-100��100������  sum����Ϊ0
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

//��ϰ1.13
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

//��ϰ1.14
//forѭ��ʹ������֪ѭ����������whileѭ��������ѭ������δ֪�ġ�

//��ϰ1.15
//error C2470: ��main��: �������������壬��û�в����б��������Եĺ�����
//error C2143: �﷨���� : ȱ�١�;��(�ڡ�:����ǰ��)
//error C2065: ��Update��: δ�����ı�ʶ��
//error C2143: �﷨���� : ȱ�١�;��(�ڡ�std::endl����ǰ��)
//error C2143: �﷨���� : ȱ�١�;��(�ڡ�}����ǰ��)
//error C2440: ����ʼ����: �޷��ӡ�const char [6]��ת��Ϊ��int��
//error C2065: ��v��: δ�����ı�ʶ��
//error C2065: ��cout��: δ�����ı�ʶ��
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

//��ϰ1.16
//ͬ��

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

//��ϰ1.17��1.18ͬ��
//��ϰ1.19
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