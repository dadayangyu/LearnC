#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void  Show(int n)
{
	//��ӡһ���������Ƶ�����λ��ż��λ
	int i = 0;
	printf("����λ��");
	for (i = 30; i >= 0; i -= 2)
	{
		if (n & (1 << i)) //��1�������ƣ���&���ǰ�λ�����㣬��0&0=0��0&1=0;1&0=0;1&1=0
		{
			printf("%d ", 1);
		}
		else  {
			printf("%d ", 0);
		}
	}
	printf("\n");
	printf("ż��λ��");
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