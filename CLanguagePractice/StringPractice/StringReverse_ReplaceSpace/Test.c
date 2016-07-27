#include <stdio.h>

extern void WordReverse(char* str);
extern void StringReplace(char* str, int size);

void TestWordReverse()
{
	char str[] = "student a am i";
	WordReverse(str);
	printf("%s\n", str);
}

void TestStrReplace()
{
	char str[20] = "we are happy!";
	StringReplace(str, sizeof(str)/sizeof(str[0]));
	printf("%s\n", str);
}
int main()
{	
	TestWordReverse();
//	TestStrReplace();
	return 0;
}