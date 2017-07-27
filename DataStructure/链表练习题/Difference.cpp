/*************************************************************************
	> File Name: Difference.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 四  7/27 18:08:46 2017
 ************************************************************************/

#include<iostream>
#include<cassert>
using namespace std;
//已知集合A和B的元素分别用不含头结点的单链表存储，函数difference()用于求解集合A与B的差集，并将结果保存在集合A的单链表中。例如，若集合A={5,10,20,15,25,30}，集合B={5,15,35,25}，完成计算后A={10,20,30}。 
//思路：将A链表的元素与B里面的所有元素进行比较，一旦相等就从A中删除该结点。｀
struct node 
{ 
	int elem; 
	node* next; 
	node(int data)
		:elem(data)
		 ,next(NULL)
	{}
};

void difference(node** LA , node* LB)
{
	assert(LA);
	node *curA = *LA;
	node *curB = LB;
	node *prev = NULL;
	while(curA)
	{
		curB = LB;
		while(curB)
		{
			if(curA->elem == curB->elem)
			{
				node *del = curA;
				if(prev == NULL)
				{
					curA = curA->next;	
					*LA = curA;
				}
				else
				{
					prev->next = curA->next;
					curA = curA->next;
				}
				delete del;
				break;
			}
			curB = curB->next;
		}
		if(curB == NULL && curA) //B中没找到A的元素
		{
			prev = curA;
			curA = curA->next;
		}
	}
}

void Print(node *list)
{
	node *cur = list;
	while(cur)
	{
		cout << cur->elem << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main()
{
	node *n1 = new node(5);
	node *n12= new node(10);
	node *n2 = new node(15);
	node *n3 = new node(20);
	node *n4 = new node(15);
	node *n5 = new node(25);
	node *n6 = new node(30);
	n1->next = n12;
	n12->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;

	node *n7 = new node(5);
	node *n8 = new node(15);
	node *n9 = new node(35);
	node *n10= new node(25);
	n7->next = n8;
	n8->next = n9;
	n9->next = n10;

	difference(&n1, n7);
	Print(n1);
	
	return 0;
}
