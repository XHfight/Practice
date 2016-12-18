/*************************************************************************
	> File Name: 1.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Fri 28 Oct 2016 11:32:42 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;

//题目：为CMyString添加赋值运算符重载函数
class CMyString
{
public:
	CMyString()
		:m_pData(NULL)
	{}
	CMyString(const CMyString& str)
	{
		//
	}	
	/*
	 *方法一：开辟新的空间，将原来的值拷贝进来，然后删除旧空间
	 *方法二：拷贝构造出临时对象，交换指向空间
	 */
	CMyString operator=(const CMyString& str)
	{
		if(&str != this)
		{
			CMyString tmp(str);
			swap(tmp.m_pData, m_pData);
		}
		return *this;
	}
private:
	char* m_pData;
};

