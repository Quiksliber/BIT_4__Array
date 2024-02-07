#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void main_game()
{
	char mine[ROWS][COLS] = { 0 };//表示布置好的雷。
	char show[ROWS][COLS] = { 0 };//表示排查出雷的个数。
	
	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//打印一次棋盘
	DisplayBoard(show, ROW, COL);

	//先布雷，再排雷
	SetMine(mine, ROW, COL);
	FindMine(mine, show, ROW, COL);
}