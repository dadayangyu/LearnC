#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ROW 3
#define MAX_COL 3
int menu(){
	printf("--------------------\n");
	printf("1.开始游戏");
	printf("0.结束游戏");
	printf("--------------------\n");
	printf("请输入您的选择：");
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
		printf("请玩家输入坐标（行，列）：");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			printf("玩家输入有误");
			continue;
		}
		//校验玩家落子地方是否有子
		if (chessBoard[row][col] != ' '){
			printf("您落子的地方已经有子了");
			continue;
		}
		chessBoard[row][col] = 'x';
		break;
	}
}
int isfull(char chessBoard[MAX_ROW][MAX_COL]){
	//找空格，如果找不到就是满了
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
	//判定所有行
	for (int row = 0; row < MAX_ROW; row++){
		if (chessBoard[row][0] != ' '&&chessBoard[row][0] == chessBoard[row][1] && chessBoard[row][0] == chessBoard[row][2]){
			return chessBoard[row][0];
		}
	}
	//判定所有列
	for (int col = 0; col < MAX_COL; col++){
		if (chessBoard[0][col] != ' '&&chessBoard[0][col] == chessBoard[1][col] && chessBoard[0][col] == chessBoard[2][col]){
			return chessBoard[0][col];
		}
	}
	//判定两个对角线
	if (chessBoard[0][0] != ' '&&chessBoard[0][0] == chessBoard[1][1] && chessBoard[0][0] == chessBoard[2][2]){
		return chessBoard[0][0];
	}
	if (chessBoard[0][2] != ' '&&chessBoard[0][2] == chessBoard[1][1] && chessBoard[0][2] == chessBoard[2][2]){
		return chessBoard[0][2];
	}
	//和棋情况
	if (isfull(chessBoard)){
		return 'q';
	}
	return ' ';
}

void computermove(char chessBoard[MAX_ROW][MAX_COL]){
	while (1){
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		//保证随机落子地方无子
		if (chessBoard[row][col] != ' '){
			continue;
		}
		chessBoard[row][col] = 'o';
		break;
	}
}
void game(){
//1.创建棋盘并开始初始化
	char chessBoard[MAX_ROW][MAX_COL] = { 0 };
	init(chessBoard);
	char winner = ' ';
	while (1){
		//2.打印棋盘
		printChessBoard(chessBoard);
		//3.玩家落子并判断输赢
		playermove(chessBoard);
		winner=iswin(chessBoard);
		if (winner != ' '){
			break;
		}
		//4.电脑落子并判断输赢
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
