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
	//�ݹ鷽ʽ��ӡһ��������ÿһλ
	//���ó�����ʹ��ÿһλ�����Ա�ʾ�������ֱ����1,10,100,100����
	//�ֱ��������ڣ�ֱ���������ȫ��λ�������
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
		printf("������һ������");
		scanf("%d", &i);
		for (j = 2; j <= i; j++)             //��֤��������2~�������м��һ����
		{
			if (i % j == 0)                  //�������պ��ܱ�����
				break;
		}
		if (i == j)                          //ȷ���ܽ��������������Ƿ��Ǳ������������Ǳ����������������������Ǻ���
			printf("%d ��һ������\n", i);
		else
			printf("%d ��������\n", i);*/
int main()
{
	int year, a;
	printf("��������ݣ�\n");
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
		printf("%d ����������\n", year);
	}
	else
	{
		printf("%d ���������\n", year);
	}
	return 0;
	system("pause");
}
	
