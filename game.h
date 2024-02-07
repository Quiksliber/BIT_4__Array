#pragma once

//头文件的包含
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

//符号的定义
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define easy_mine 10

//游戏所含的函数的声明
void menu();//目录菜单
void main_game();//主游戏
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//棋盘的初始化
void DisplayBoard(char board[ROWS][COLS], int row, int col);//棋盘的打印
void SetMine(char board[ROWS][COLS], int row, int col);//布雷的函数
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//排雷的函数
int GetMineCount(char mine[ROWS][COLS], int x, int y);
