#include "DoubleStack.h"
#include "QueueByTwoStack.h"
#include "StackByTwoQueue.h"

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

void TestQueueByTwoStack()
{
	Queue<int> q1;
	q1.Push(1);
	q1.Push(2);
	q1.Push(3);
	q1.Push(4);

	cout << q1.Front() << endl;
	cout << q1.Back() << endl;
	q1.Pop();
	cout << q1.Front() << endl;
	cout << q1.Back() << endl;
	cout << q1.Size() << endl;
}


void TestStackByTwoQueue()
{
	Stack<int> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	cout << s1.Size() << endl;
	while (!s1.Empty())
	{
		cout << s1.Top() << endl;
		s1.Pop();
	}

}
int main()
{
	//TestDouStack();
	//TestQueueByTwoStack();
	TestStackByTwoQueue();
	system("pause");
	return 0;
}