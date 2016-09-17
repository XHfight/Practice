#include "DoubleStack.h"
#include <string>
void TestDouStack() //测试一个数组实现两个栈
{
	DouStack<int> s1;
	s1.Push(1, 1);
	s1.Push(1, 2);
	s1.Push(1, 3);
	s1.Push(1, 3);
	s1.Push(1, 3);
	s1.Push(1, 3);
	//s1.Push(1, 3);


	s1.Push(2, 4);
	s1.Push(2, 3);
	s1.Push(2, 2);
	s1.Push(2, 1);


	cout<<s1.Size(1)<<endl;

	cout<<s1.Size(2)<<endl;


	while (!s1.Empty(1))
	{
		cout << s1.Top(1) << " ";
		s1.Pop(1);
	}
	cout << endl;

	while (!s1.Empty(2))
	{
		cout << s1.Top(2) << " ";
		s1.Pop(2);
	}
	cout << endl;

}


int main()
{
	TestDouStack();
	system("pause");
	return 0;
}