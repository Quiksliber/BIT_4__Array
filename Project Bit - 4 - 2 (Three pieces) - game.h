#pragma once

//头文件的包含
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

//符号的定义
#define ROW 3
#define COL 3

//游戏所含的函数的声明
void menu();//目录菜单
void main_game();//主游戏
void board_initialization(char board[ROW][COL], int row, int col);//板面初始化
void board_printing(char board[ROW][COL], int row, int col);//板面打印
char win(char board[ROW][COL], int row, int col);//胜负判断
void winner_printing(char outcome);
