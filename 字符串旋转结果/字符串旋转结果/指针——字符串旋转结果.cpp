#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void left_move(char *s1, int k)//һ������Ϊ�ַ����׵�ַ��һ�����ƶ���ƫ����
{
	while (k != 0)
	{
		char *str = s1;
		char tmp = *str;
		while ((*(str + 1)) != '\0')
		{
			*str = *(str + 1);
			str++;
		}
		*str = tmp;
		k--;
	}
}

int judge_function(char *s1, const char *s2)//һ������Ϊ�ַ����׵�ַ������һ���ǱȽϵ��ַ����׵�ַ
{
	unsigned int i = 0;
	if (strlen(s1) != strlen(s2))
	{
		return 0;
	}
	else
	for (i = 0; i <= (strlen(s1) - 1); i++)
	{
		left_move(s1, 1);
		if (strcmp(s1, s2) == 0)//strcmp�����ж���ת���s1�ַ����Ƿ���s2�ַ�����ͬ
		{
			return 1;
		}
	}
	return 0;
}


int main(){
	//�ַ�����ת���
	//�Ƚ��ַ������ƶ�һ�αȽ�һ�Σ�ֱ���ҵ�ƥ���һ������ַ�������ָ�룩
	//�ҵ�ƥ���һ��Ļ�����������ָ���ƶ����ٴΣ����ؼ�
	//δ�ҵ�ƥ���һ��Ļ�����ô�ͷ���0
	char s1[] = "AABCD";
	char s2[] = "BCDAA";

	char s3[] = "abcd";
	char s4[] = "ACBD";

	char s5[] = "AABCD";
	char s6[] = "BCDA";

	int res1 = judge_function(s1, s2);
	int res2 = judge_function(s3, s4);
	int res3 = judge_function(s5, s6);
	printf("%d\n", res1);
	printf("%d\n", res2);
	printf("%d\n", res3);
	system("pause");
	return 0;
}