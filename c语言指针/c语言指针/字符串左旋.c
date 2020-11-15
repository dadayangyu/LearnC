#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int main(){
	//实现字符串左旋k个字符（k>0）
	//先整体左移一个字符,然后把首字符（存储起来）放到最后一个字符的位置
	//重复上述的做法K次实现字符串的左旋
	char str[] = "ABCDEF";
	int k = 0;
	int len = strlen(str);
	scanf("%d", &k);
	for (int i = 0; i < k; i++){
		int tmp = *str;//存储首元素
		for (int j = 0; j < len; j++){
			*(str + j) = *(str + j + 1);
		}
		*(str + len - 1) = tmp;
	}
	printf("%s", str);
	system("pause");
	return 0;
}