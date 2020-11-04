#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ROW 3
#define MAX_COL 3
int menu(){
	printf("--------------------\n");
	printf("1.��ʼ��Ϸ");
	printf("0.������Ϸ");
	printf("--------------------\n");
	printf("����������ѡ��");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
void init(char chessBoard[MAX_ROW][MAX_COL]){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			chessBoard[row][col] = ' ';
		}
	}
}
void printChessBoard(char chessBoard[MAX_ROW][MAX_COL]){
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++){
			printf("| %c | %c | %c |\n", chessBoard[row][0],chessBoard[row][1],chessBoard[row][2]);
		printf("+---+---+---+\n");
	}
}
void playermove(char chessBoard[MAX_ROW][MAX_COL]){
	while (1){
		printf("������������꣨�У��У���");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			printf("�����������");
			continue;
		}
		//У��������ӵط��Ƿ�����
		if (chessBoard[row][col] != ' '){
			printf("�����ӵĵط��Ѿ�������");
			continue;
		}
		chessBoard[row][col] = 'x';
		break;
	}
}
int isfull(char chessBoard[MAX_ROW][MAX_COL]){
	//�ҿո�����Ҳ�����������
	for (int row = 0; row <= MAX_ROW; row++){
		for (int col = 0; col <= MAX_COL; col++){
			if (chessBoard[row][col] == ' '){
				return  0;
			}
		}
	}
	return 1;
}
char iswin(char chessBoard[MAX_ROW][MAX_COL]){
	//�ж�������
	for (int row = 0; row < MAX_ROW; row++){
		if (chessBoard[row][0] != ' '&&chessBoard[row][0] == chessBoard[row][1] && chessBoard[row][0] == chessBoard[row][2]){
			return chessBoard[row][0];
		}
	}
	//�ж�������
	for (int col = 0; col < MAX_COL; col++){
		if (chessBoard[0][col] != ' '&&chessBoard[0][col] == chessBoard[1][col] && chessBoard[0][col] == chessBoard[2][col]){
			return chessBoard[0][col];
		}
	}
	//�ж������Խ���
	if (chessBoard[0][0] != ' '&&chessBoard[0][0] == chessBoard[1][1] && chessBoard[0][0] == chessBoard[2][2]){
		return chessBoard[0][0];
	}
	if (chessBoard[0][2] != ' '&&chessBoard[0][2] == chessBoard[1][1] && chessBoard[0][2] == chessBoard[2][2]){
		return chessBoard[0][2];
	}
	//�������
	if (isfull(chessBoard)){
		return 'q';
	}
	return ' ';
}

void computermove(char chessBoard[MAX_ROW][MAX_COL]){
	while (1){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		//��֤������ӵط�����
		if (chessBoard[row][col] != ' '){
			continue;
		}
		chessBoard[row][col] = 'o';
		break;
	}
}
void game(){
//1.�������̲���ʼ��ʼ��
	char chessBoard[MAX_ROW][MAX_COL] = { 0 };
	init(chessBoard);
	char winner = ' ';
	while (1){
		//2.��ӡ����
		printChessBoard(chessBoard);
		//3.������Ӳ��ж���Ӯ
		playermove(chessBoard);
		winner=iswin(chessBoard);
		if (winner != ' '){
			break;
		}
		//4.�������Ӳ��ж���Ӯ
		computermove(chessBoard);
		winner = iswin(chessBoard);
		if (winner != ' '){
			break;
		}

	}
	printChessBoard(chessBoard);
	if (winner == 'x'){
		printf("you win");
	}
	else if (winner == 'o'){
		printf("you lose");
	}
	else{
		printf("fifteenall");
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
	}
	system("pause");
	return 0;
}
