#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 5
int main(){
	//打印杨辉三角
	//杨辉三角的特点：每个数字等于上一行的左右两个数字之和。
	//可用此性质写出整个杨辉三角。即第n+1行的第i个数等于第n行的第i-1个数和第i个数之和，这也是组合数的性质之一。
	//两边的数特殊，全是1
	int j,i,a[N][N];
	int n = 0;
	printf("请输入要打印的数");
    scanf("%d", &n);
	printf("%d行杨辉三角如下：\n", n);
	for (i = 1; i <= n; i++){
		a[i][1] = a[i][i] = 1;
	}
	//第一行是1，第二行也是1，所以规律从第三行开始(不能从第三行开始，？？？？)
	for (i = 1; i <= n; i++){
		for (j = 2; j <= i - 1;j++)
		a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
	}
	for (i = 0; i <= n; i++){
		for (j = 1; j <= i; j++){
			printf("%6d", a[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	system("pause");
	return 0;

}