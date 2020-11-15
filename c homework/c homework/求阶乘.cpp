#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//int main(){
	/*int m, n, i, sum = 1;
	printf("please input one number!");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		sum = sum*i;
	}
	printf("sum=%d", sum);
	system("pause");
	return 0;
	*/
	//递归方式打印一个整数的每一位
	//采用除法，使得每一位都可以表示出来，分别除以1,10,100,100……
	//分别设立出口，直到这个整数全部位数都输出
   /* void Print(int n)
	{
		if (n > 9)
		{
			Print(n / 10);
		}
		printf("%d\n", n % 10);
	}
	int main()
	{
		Print(1234);
		system("pause");
		return 0;
		*/
/*	int main(){
		int i, j;
		printf("请输入一个数：");
		scanf("%d", &i);
		for (j = 2; j <= i; j++)             //保证除数是在2~被除数中间的一个数
		{
			if (i % j == 0)                  //被除数刚好能被整除
				break;
		}
		if (i == j)                          //确定能将被除数整数的是否是被除数本身，若是本身则是素数，若不是则是合数
			printf("%d 是一个素数\n", i);
		else
			printf("%d 不是素数\n", i);*/
int main()
{
	int year, a;
	printf("请输人年份：\n");
	scanf("%d", &year);
	if (year % 400 == 0)
		a = 1;
	else
	{
		if (year % 4 == 0 && year % 100 != 0)
			a = 1;
		else
			a = 0;
	}
	if (a == 1)
	{
		printf("%d 此年是闰年\n", year);
	}
	else
	{
		printf("%d 此年非闰年\n", year);
	}
	return 0;
	system("pause");
}
	
