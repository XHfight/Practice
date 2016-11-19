/*
给出一百分制成绩，要求输出成绩等级‘A’、‘B’、‘C’、‘D’、‘E’。 90分以上为A 80-89分为B 70-79分为C 60-69分为D 60分以下为E
*/
#include <iostream>
using namespace std;

int main()
{
	int score = 0;
	cin >> score;

	if(score>=90)
		cout << "A";
	else if(score>=80)
		cout << "B";
	else if(score>=70)
		cout << "C";
	else if(score>=60)
		cout << "D";
	else
		cout << "E";	
	
	return 0;
}
