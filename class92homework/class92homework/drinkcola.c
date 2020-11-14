#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main(){
	int m=0;
	int n=0;
	printf("请输入两个数：");
	scanf("%d %d", &m, &n);
	m = m^n;
	n = m^n;
	m = m^n;
	printf("m=%d n=%d\n", m, n);
	system("pause");
	return 0;
}