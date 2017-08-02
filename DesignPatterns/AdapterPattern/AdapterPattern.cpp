
#include<iostream>
using namespace std;

//目标类
class Target
{
public:
	virtual void Request()
	{
		cout << "target request" << endl;
	}
};

//原类
class Adaptee
{
public:
	void SpecificRequest()
	{
		cout << "specific request" << endl;
	}
};

//适配器
class Adapter : public Target, Adaptee
{
	public:
	void Request()
	{
		Adaptee::SpecificRequest();
	}
};

int main()
{
	Target * obj= new Adapter();
	obj->Request();
	delete obj;
	obj = NULL;
	return 0;
}
