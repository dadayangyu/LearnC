#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n = 0;
	printf("请输入一个整数:");
	scanf("%d", &n);
	int count = 0;
	while (n != 0){
		n &= n - 1;
		count++;
	}
	printf("%d", count); 
	system("pause");
	return 0;
}