#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 5
int main(){
	//��ӡ�������
	//������ǵ��ص㣺ÿ�����ֵ�����һ�е�������������֮�͡�
	//���ô�����д������������ǡ�����n+1�еĵ�i�������ڵ�n�еĵ�i-1�����͵�i����֮�ͣ���Ҳ�������������֮һ��
	//���ߵ������⣬ȫ��1
	int j,i,a[N][N];
	int n = 0;
	printf("������Ҫ��ӡ����");
    scanf("%d", &n);
	printf("%d������������£�\n", n);
	for (i = 1; i <= n; i++){
		a[i][1] = a[i][i] = 1;
	}
	//��һ����1���ڶ���Ҳ��1�����Թ��ɴӵ����п�ʼ(���ܴӵ����п�ʼ����������)
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