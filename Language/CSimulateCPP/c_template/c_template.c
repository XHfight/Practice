/*************************************************************************
	> File Name: c_template.c
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 五  7/ 7 23:43:26 2017
 ************************************************************************/

//c模拟实现模板函数
//模板：一个函数可以处理不同类型参数
//思路一：利用回调函数，让函数指针作为参数。参考qsort函数
//思路二：利用宏。选择这个，方便调试，比较直观。
//以add函数为例：
//c++模板写法如下：
//tempalate<class T>
//T add(T a, T b)
//{
//	return a+b;
//}

#include<stdio.h>

//取消宏定义，以免被包含进来的其他文件中使用此功能，而产生错误。
#undef ReturnType
#undef ElementType
#undef CallFunction

//定义“仿真模板”
#define ReturnType int
#define ElementType int
#define CallFunction(ret, a, b) \
{ \
	ret = a + b; \
}
//一定要在宏定义完引入，不然上面三个就未定义，找不到
#include"c_template.h"

int main()
{
	int b = Add(1, 2);
	printf("%d\n", b);
	return 0;
}

