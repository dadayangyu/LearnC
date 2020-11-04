#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ROW 9
#define MAX_COL 9
#define DEFAULT_MINE_COUNT 10
//创建菜单
int menu(){
	//菜单构造的形式（0表示游戏开始，1表示游戏结束）
	printf("=======================");
	printf("0.游戏开始");
	printf("1.游戏结束");
	printf("请输入您的选择");
	printf("=======================");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}
//先打印showmap全*，再打印minemap(0为没有，1为炸弹)
void init(char showmap[MAX_ROW][MAX_COL], char minemap[MAX_ROW][MAX_COL]){
	//初始化showmap，全部设为*
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			showmap[row][col] = '*';
		}
	}
	//初始化minemap，先全部设为0，然后随机生成几个1
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			minemap[row][col] = '0';
		}
	}
	//使用宏定义解决majic number问题
	int n = DEFAULT_MINE_COUNT;
	while (n>0){
		//随机生成雷的位置
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (minemap[row][col] == '1'){
			//如果当前位置已经有雷，就直接进入到下次循环重新产生随机位置
			continue;
		}
		//重点容易被遗忘
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

	//创建地图并开始初始化
	char minemap[MAX_ROW][MAX_COL] = { 0 };
	char showmap[MAX_ROW][MAX_COL] = { 0 };
	init(showmap, minemap);   //设计地图的函数（关键）
	int openedBlockCount = 0;   //翻开无雷的格子数开始为0
	//打印地图(打印地图并且随机设置炸弹的位置)另外设计函数
	while (1){
		printmap(minemap);
		printf("=======================\                                                                                                                    n");
		printmap(showmap);
		int row = 0;
		int col = 0;
		printf("请输入要翻开的坐标（行,列）：");
		scanf("%d %d", &row, &col);
		//程序读取玩家输入要翻开的坐标并校验
		//要判断用户输入是否正确
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			printf("您输入的坐标有误\n");
			continue;

		}
		if (showmap[row][col] != '*'){
			printf("当前位置已经被翻开！\n");
			continue;
		}
		//判定该位置的坐标是否是地雷，如果是地雷，直接结束游戏
		if (minemap[row][col] == '1'){
			printf("game over!\n");
			printmap(minemap);
			break;
		}
		//如果不是地雷，统计当前位置周围地雷的个数，并显示到地图上
		updateshowmap(showmap, minemap, row, col);
		//判定游戏是否胜利(判断不是雷的地方是不是都翻开了)
		openedBlockCount++;
		if (openedBlockCount == MAX_COL*MAX_ROW - DEFAULT_MINE_COUNT){
			printf("游戏胜利！/n");
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
			printf("您输入的有误！\n");
			break;
		}
	}
	system("pause");
	return 0;
}