/*
����һ�ٷ��Ƴɼ���Ҫ������ɼ��ȼ���A������B������C������D������E���� 90������ΪA 80-89��ΪB 70-79��ΪC 60-69��ΪD 60������ΪE
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
