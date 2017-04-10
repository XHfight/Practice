/*************************************************************************
	> File Name: 5.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Sun 20 Nov 2016 09:55:38 AM CST
 ************************************************************************/

//面试题5：逆序打印链表
//面试题13：在O（1）时间删除链表结点
//面试题15：链表中的倒数第K个结点
//面试题16：反转链表
//面试题17：合并两个排序的链表
//面试题37：两个链表的第一个公共结点

#include <iostream>
#include <stack>
#include <cassert>
#include <cmath>
using namespace std;

typedef int DataType;
struct ListNode
{
	DataType _data;
	ListNode* _next;

	ListNode(DataType data)
	:_data(data)
	,_next(NULL)
	{}
};

class List
{
	typedef ListNode Node;
public:
	List()
	:_head(NULL)
	{}

	List(Node* head)
	:_head(head)
	{}

	void PushBack(DataType data)
	{
		if(_head == NULL)
		{
			_head = new Node(data);
		}
		else
		{
			Node* cur = _head;
			while(cur->_next != NULL)
			{
				cur = cur->_next;
			}
			cur->_next = new Node(data);
		}
	}

	//面试题5:从尾到头输出链表
	//法1：递归打印
	//缺点：如果链表太长，可能会栈溢出；函数调用开销大
	void ReversePrint1()
	{
		_ReversePrint(_head);
		cout << endl;
	}
	//法2：借助栈，后进先出
	void ReversePrint2()
	{
		Node* cur = _head;
		stack<Node*> s;
		while(cur)
		{
			s.push(cur);
			cur = cur->_next;
		}
		
		while(!s.empty())
		{
			cout << s.top()->_data << " ";
			s.pop();
		}
		cout << endl;
	}
	//法3：先逆置链表，再顺序打印。
	//缺点：改变了链表的结构
	void ReversePrint3()
	{
		_head = ReverseList();
		Print();
	}

	//面试题13：在O(1)时间删除链表结点
	//交换删除法
	void DeleteNode(Node* pToBeDeleted)
	{
		if(pToBeDeleted == NULL)
			return;
		//如果删除的结点为尾结点
		if(pToBeDeleted->_next == NULL)
		{
			if(pToBeDeleted == _head)
			{
				_head = NULL;
			}
			else
			{
				Node* cur = _head;
				while(cur && cur->_next != pToBeDeleted)
				{
					cur = cur->_next;
				}
				if(cur)
					cur->_next = NULL;
			}
			delete pToBeDeleted;
			pToBeDeleted = NULL;
			return;
		}

		Node* del = pToBeDeleted->_next;
		pToBeDeleted->_data = pToBeDeleted->_next->_data;
		pToBeDeleted->_next = pToBeDeleted->_next->_next;
		delete del;
		del = NULL;
	}

	//面试题15：链表中的倒数第K个结点
	//思路：定义快慢指针，让快指针先走k步，然后快慢指针一起走。
	Node* Back_K(int k)
	{
		Node* fast = _head;
		Node* slow = _head;
		int num = k;
		while(num)
		{
			fast = fast->_next;
			num--;
		}

		while(fast)
		{
			fast = fast->_next;
			slow = slow->_next;
		}
		return slow;
	}

	//面试题16:反转链表
	Node* ReverseList()
	{
		Node* cur = _head;
		Node* newHead = NULL;
		while(cur)
		{
			Node* tmp = cur;
			cur = tmp->_next;
			tmp->_next = newHead; 
			newHead = tmp;
		}
		return newHead;
	}

	//面试题17：合并两个排序的链表
	//从小到大排序
	Node* Merge(List list)
	{
		Node* firList = _head;
		Node* secList = list._head;
		Node* newHead = NULL;
		Node* firCur = firList;
		Node* secCur = secList;
		if(firList)
		{
			newHead = firList;
			firCur = firCur->_next;  //一定要向后走一步，不然后面会死循环
		}
		else
		{
			newHead = secList;
			secCur = secCur->_next;
		}

		Node* cur = newHead;
		while(firCur && secCur)
		{
			if(firCur->_data < secCur->_data)
			{
				cur->_next = firCur;
				firCur = firCur->_next;
			}
			else
			{
				cur->_next = secCur;
				secCur = secCur->_next;
			}
			cur = cur->_next;
		}
		if(firCur)
		{
			cur->_next = firCur;
		}
		else
		{
			cur->_next = secCur;
		}
		return newHead;
	}
	
	//面试题37：两个链表的第一个公共结点
	//思路1：嵌套循环，在一个链表中逐个查找另一个链表中的结点，O(n^2),效率低
	//思路2：只要有公共结点，从公共结点以后的结点完全相同，所以可以求出两个链表的长度
	//让长的链表先走多出来的步数，然后两个一起走，边走边判断。
	Node* FirCommon(List l)
	{
		int len1 = GetLen();
		int len2 = l.GetLen();
		Node *cur1 = _head;
		Node *cur2 = l._head;
		if(len1 > len2)
		{
			int step = len1 - len2;
			while(step)
			{
				cur1 = cur1->_next;
				--step;
			}
		}
		else
		{
			int step = len2 - len1;
			while(step)
			{
				cur2 = cur2->_next;	
				--step;
			}
		}
		
		while(cur1 && cur2 && cur1!=cur2)
		{
			++cur1;
			++cur2;
		}
		if(cur1 == cur2)
			return cur1;
		else
			return NULL;
	}

	int GetLen()
	{
		int count = 0;
		Node *cur = _head;
		while(cur)
		{
			++count;
			cur = cur->_next;
		}
		return count;
	}
	//打印链表
	void Print()
	{
		Node* cur = _head;
		while(cur)
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		cout << endl;
	}

	Node* Find(DataType find)
	{
		Node* cur = _head;
		while(cur)
		{
			if(cur->_data == find)
			{
				return cur;
			}
			cur = cur->_next;
		}
		return NULL;
	}

	void Insert(size_t k, Node* node)
	{
		int n = k;
		Node* cur = _head;
		while(cur && n>0)
		{
			--n;
			cur = cur->_next;
		}
		if(k == 0)
		{
			_head = node;
			_head->_next = NULL;
		}
		if(cur)
		{
			node->_next = cur->_next;
			cur->_next = node;
		}
	}

protected:
	void _ReversePrint(Node* node)
	{
		if(node == NULL)
			return;
		else
		{
			_ReversePrint(node->_next);
			cout << node->_data << " ";
		}
	}
protected:
	Node* _head;
};

void Test5()
{
	List l;
	for(int i = 1; i <= 10; ++i)
	{
		l.PushBack(i);
	}
	l.ReversePrint1();
	l.ReversePrint2();
	l.ReversePrint3();
}

void Test13()
{
	List l;
	for(int i = 1; i<=10; ++i)
	{
		l.PushBack(i);
	}
	ListNode* ret5 = l.Find(5);
	l.DeleteNode(ret5);
	ListNode* ret10 = l.Find(10);
	l.DeleteNode(ret10);
	ListNode* ret1 = l.Find(1);
	l.DeleteNode(ret1);
	l.Print();
}

void Test15()
{
	int k = 3;
	List l;
	for(int i = 1; i<=10; ++i)
	{
		l.PushBack(i);
	}
	l.Print();
	cout << "3:" << l.Back_K(k)->_data << endl;
	k = 10;
	cout << "10:" << l.Back_K(k)->_data << endl;
	k = 1;
	cout << "1:" << l.Back_K(k)->_data << endl;
}

void Test17()
{
	List l1;
	for(int i = 1; i<=10; i+=2)
	{
		l1.PushBack(i);
	}
	List l2;
	l2.PushBack(2);
	l2.PushBack(4);
	cout << "l1:";
	l1.Print();
	cout << "l2:";
	l2.Print();
	List newList = l1.Merge(l2);
	newList.Print();
}

void Test37()
{
	List l1;
	List l2;
	ListNode *comm = NULL;
	for(int i = 1; i<=10; i+=2)
	{
		l1.PushBack(i);
	}
	l2 = l1;
	comm = l1.FirCommon(l2);
	cout << "test 1:相同链表,答案：1" << endl;
	if(comm == NULL)
		cout << "没有交点" << endl;
	else
		cout << "第一个相交点：" << comm->_data << endl;
	
	List l3;
	l3.PushBack(1);
	comm = l1.FirCommon(l3);
	cout << "test 2:没有交点" << endl;
	if(comm == NULL)
		cout << "没有交点" << endl;
	else
		cout << "第一个相交点：" << comm->_data << endl;

	List l4;
	l4.Insert(0, l1.Find(5));
	comm = l1.FirCommon(l4);
	cout << "test 3:正常 ,答案：5" << endl;
	if(comm == NULL)
		cout << "没有交点" << endl;
	else
		cout << "第一个相交点：" << comm->_data << endl;

}

int main()
{
	//Test5();
	//Test13();
	//Test15();
	//Test17();
	Test37();
	return 0;
}
