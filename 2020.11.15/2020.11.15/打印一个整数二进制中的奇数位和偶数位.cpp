#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void  Show(int n)
{
	//打印一个数二进制的奇数位和偶数位
	int i = 0;
	printf("奇数位：");
	for (i = 30; i >= 0; i -= 2)
	{
		if (n & (1 << i)) //对1进行左移；‘&’是按位与运算，即0&0=0；0&1=0;1&0=0;1&1=0
		{
			printf("%d ", 1);
		}
		else  {
			printf("%d ", 0);
		}
	}
	printf("\n");
	printf("偶数位：");
	for (i = 31; i >= 0; i -= 2)
	{
		if (n & (1 << i)) {
			printf("%d ", 1);
		}
		else
		{
			printf("%d ", 0);
		}
	}
	printf("\n");
}
int main()
{
	int m = 0;
	scanf("%d", &m);
	Show(m);
	system("pause");
	return 0;
}