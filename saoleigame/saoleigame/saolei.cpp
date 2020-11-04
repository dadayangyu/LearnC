#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ROW 9
#define MAX_COL 9
#define DEFAULT_MINE_COUNT 10
//�����˵�
int menu(){
	//�˵��������ʽ��0��ʾ��Ϸ��ʼ��1��ʾ��Ϸ������
	printf("=======================");
	printf("0.��Ϸ��ʼ");
	printf("1.��Ϸ����");
	printf("����������ѡ��");
	printf("=======================");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
//�ȴ�ӡshowmapȫ*���ٴ�ӡminemap(0Ϊû�У�1Ϊը��)
void init(char showmap[MAX_ROW][MAX_COL], char minemap[MAX_ROW][MAX_COL]){
	//��ʼ��showmap��ȫ����Ϊ*
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			showmap[row][col] = '*';
		}
	}
	//��ʼ��minemap����ȫ����Ϊ0��Ȼ��������ɼ���1
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			minemap[row][col] = '0';
		}
	}
	//ʹ�ú궨����majic number����
	int n = DEFAULT_MINE_COUNT;
	while (n>0){
		//��������׵�λ��
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (minemap[row][col] == '1'){
			//�����ǰλ���Ѿ����ף���ֱ�ӽ��뵽�´�ѭ�����²������λ��
			continue;
		}
		//�ص����ױ�����
		minemap[row][col] = '1';
		n--;
	}
}
void printmap(char themap[MAX_ROW][MAX_COL]){
	printf("   |");
	for (int col = 0; col < MAX_COL; col++){
		printf("%d", col);
	}
	printf("\n");
	printf("--+---------------------\n");
	for (int row = 0; row < MAX_ROW; row++){
		printf(" %d|", row);
		for (int col = 0; col < MAX_COL; col++){
			printf("%c ", themap[row][col]);
		}
		printf("\n");
	}
}
void updateshowmap(char showmap[MAX_ROW][MAX_COL], char minemap[MAX_ROW][MAX_COL], int row, int col){
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++){
		for (int c = col - 1; c <= col + 1; c++){
			if (r < 0 || r >= MAX_ROW || c < 0 || c >= MAX_COL){
				continue;
			}
			if (minemap[r][c] == '1'){
				count++;
			}
		}
	}
	showmap[row][col] = count + '0';
}
void game(){

	//������ͼ����ʼ��ʼ��
	char minemap[MAX_ROW][MAX_COL] = { 0 };
	char showmap[MAX_ROW][MAX_COL] = { 0 };
	init(showmap, minemap);   //��Ƶ�ͼ�ĺ������ؼ���
	int openedBlockCount = 0;   //�������׵ĸ�������ʼΪ0
	//��ӡ��ͼ(��ӡ��ͼ�����������ը����λ��)������ƺ���
	while (1){
		printmap(minemap);
		printf("=======================\                                                                                                                    n");
		printmap(showmap);
		int row = 0;
		int col = 0;
		printf("������Ҫ���������꣨��,�У���");
		scanf("%d %d", &row, &col);
		//�����ȡ�������Ҫ���������겢У��
		//Ҫ�ж��û������Ƿ���ȷ
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			printf("���������������\n");
			continue;

		}
		if (showmap[row][col] != '*'){
			printf("��ǰλ���Ѿ���������\n");
			continue;
		}
		//�ж���λ�õ������Ƿ��ǵ��ף�����ǵ��ף�ֱ�ӽ�����Ϸ
		if (minemap[row][col] == '1'){
			printf("game over!\n");
			printmap(minemap);
			break;
		}
		//������ǵ��ף�ͳ�Ƶ�ǰλ����Χ���׵ĸ���������ʾ����ͼ��
		updateshowmap(showmap, minemap, row, col);
		//�ж���Ϸ�Ƿ�ʤ��(�жϲ����׵ĵط��ǲ��Ƕ�������)
		openedBlockCount++;
		if (openedBlockCount == MAX_COL*MAX_ROW - DEFAULT_MINE_COUNT){
			printf("��Ϸʤ����/n");
			printmap(minemap);
			break;
		}
	}
}
int main(){
	srand((unsigned int)time(0));
	while (1){
		int choice = menu();
		if (choice == 1){
			game();
		}
		else if (choice == 0){
			printf("goodbye!\n");
			break;
		}
		else{
			printf("�����������\n");
			break;
		}
	}
	system("pause");
	return 0;
}