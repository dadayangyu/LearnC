#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main(){
	//ʵ���ַ�������k���ַ���k>0��
	//����������һ���ַ�,Ȼ������ַ����洢�������ŵ����һ���ַ���λ��
	//�ظ�����������K��ʵ���ַ���������
	char str[] = "ABCDEF";
	int k = 0;
	int len = strlen(str);
	scanf("%d", &k);
	for (int i = 0; i < k; i++){
		int tmp = *str;//�洢��Ԫ��
		for (int j = 0; j < len; j++){
			*(str + j) = *(str + j + 1);
		}
		*(str + len - 1) = tmp;
	}
	printf("%s", str);
	system("pause");
	return 0;
}