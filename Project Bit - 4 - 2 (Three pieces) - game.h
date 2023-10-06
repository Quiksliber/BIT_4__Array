#pragma once

//Inclusion of header files
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

//Definition of symbols
#define ROW 3
#define COL 3

//Declaration of functions contained in the game
void menu();//Directory menu
void main_game();//main game
void board_initialization(char board[ROW][COL], int row, int col);//Board initialization
void board_printing(char board[ROW][COL], int row, int col);//Board printing
char win(char board[ROW][COL], int row, int col);//Judgement of victory or defeat
void winner_printing(char outcome);
