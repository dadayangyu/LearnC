#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void left_move(char *s1, int k)//一个参数为字符串首地址，一个是移动的偏移量
{
	while (k != 0)
	{
		char *str = s1;
		char tmp = *str;
		while ((*(str + 1)) != '\0')
		{
			*str = *(str + 1);
			str++;
		}
		*str = tmp;
		k--;
	}
}

int judge_function(char *s1, const char *s2)//一个参数为字符串首地址，还有一个是比较的字符串首地址
{
	unsigned int i = 0;
	if (strlen(s1) != strlen(s2))
	{
		return 0;
	}
	else
	for (i = 0; i <= (strlen(s1) - 1); i++)
	{
		left_move(s1, 1);
		if (strcmp(s1, s2) == 0)//strcmp函数判断旋转后的s1字符串是否与s2字符串相同
		{
			return 1;
		}
	}
	return 0;
}


int main(){
	//字符串旋转结果
	//比较字符串，移动一次比较一次，直至找到匹配的一项（两个字符串两个指针）
	//找到匹配的一项的话，数个数看指针移动多少次，返回几
	//未找到匹配的一项的话，那么就返回0
	char s1[] = "AABCD";
	char s2[] = "BCDAA";

	char s3[] = "abcd";
	char s4[] = "ACBD";

	char s5[] = "AABCD";
	char s6[] = "BCDA";

	int res1 = judge_function(s1, s2);
	int res2 = judge_function(s3, s4);
	int res3 = judge_function(s5, s6);
	printf("%d\n", res1);
	printf("%d\n", res2);
	printf("%d\n", res3);
	system("pause");
	return 0;
}