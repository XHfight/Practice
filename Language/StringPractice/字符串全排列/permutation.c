//打印出 str 的全排列,
//如 abc 的全排列: abc, acb, bca, dac, cab, cba

#include <stdio.h>
#include <assert.h>

//方法：递归
//思路：递归的每次用第一个字符与所有的字符交换
void swap_ch(char *c1, char *c2)
{
	assert(c1&&c2);
	char tmp = *c1;
	*c1 = *c2;
	*c2 = tmp;
}
void Permutation_o(char *str, char *begin)
{
	assert(str&&begin);
	if(*(begin) == '\0')
		printf("%s\n", str);
	else
	{
		char *c = begin;
		for( ; *c != '\0'; ++c)
		{
			swap_ch(begin, c);
			Permutation_o(str, begin+1);
			swap_ch(begin, c);
		}
	}
}

void Permutation(char *str)
{
	assert(str);
	Permutation_o(str, str);
}

int main()
{
	char str[] = "abc";
	Permutation(str);
	return 0;
}
