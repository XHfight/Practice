/*************************************************************************
	> File Name: DeleteNum.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: 日  7/ 2 23:45:58 2017
 ************************************************************************/

/*题目描述：
 *有一个数组a[N]顺序存放0~N-1，要求每隔两个数删掉一个数，到末尾时循环至开头继续进行，求最后一个被删掉的数的原始下标位置。以8个数(N=7)为例:｛0，1，2，3，4，5，6，7｝，0->1->2(删除)->3->4->5(删除)->6->7->0(删除),如此循环直到最后一个数被删除。 
 */
#include <iostream>
using namespace std;

int LastDelete(int len)
{
    if(len > 1000)
        len = 999;
    
    int num = len;
    bool *status = new bool[len];
    for(int i = 0; i < len ; ++i)
    {
        status[i] = false;
    }
    
    int del = 0;
    while(len > 0)
    {
        while(status[del] == true)
        {
            ++del;
            if(del >= len)
            	del %= len;
        }
        ++del;   //status[del] == false; ++
        if(del >= len)
            del %= len;
        while(status[del] == true)
 		{
            ++del;
            if(del >= len)
            	del %= len;
        }
        ++del;   //status[del] == false; ++
        if(del >= len)
            del %= len;
        
        while(status[del] == true)
 		{
            ++del;
            if(del >= len)
            	del %= len;
        }
        status[del] = true;
    	--num;
        if(num == 1)
            break;
    }
    
    int i = 0;
    for( ; i < len; ++i)
    {
        if(status[i] == false)
            break;
    }
    return i;
}

int main()
{
    int n;  //数组的大小
    while(cin >> n)
    {
    	cout << LastDelete(n) << endl;
    }
    return 0;
}
