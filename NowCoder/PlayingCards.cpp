/*************************************************************************
	> File Name: PlayingCards.cpp
	> Author: XH
	> Mail: X_H_fight@163.com 
	> Created Time: Wed 24 May 2017 02:09:24 PM CST
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
using namespace std;
char card[14]={'3','4','5','6','7','8','9','1','J','Q','K','A','2','j'};
int main(){
   char a[20],b[20];
   int A,B;
   scanf("%[^-]-%[^\n]",a,b);
   //%[^-]就是除了"-"其他字符都可以输入,%[^\n]部分忽略换行符
   int lenl=1,lenr=1;
   for(int i=0;i<strlen(a);i++){
      if (a[i]==' ')
      lenl++;
   }
   for(int j=0;j<strlen(b);j++){
      if (b[j]==' ')
        lenr++;
   }
   for (int m=0;m<14;m++){
      if (a[0]==card[m])
         A=m;
   }
   for (int n=0;n<14;n++){
      if (b[0]==card[n])
          B=n;
   }
   if (A==13)
       cout<<a;
   else if (B==13)
       cout<<b;
   else if (lenl==lenr)
   {
      if (A>B)
	      cout<<a;
      else
          cout<<b;
   }
   else if (lenl==4)
      cout<<a;
   else if (lenr==4)
      cout<<b;
   else
      cout<<"ERROR";
   return 0;
}
