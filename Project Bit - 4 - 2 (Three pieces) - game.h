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
void menu();
void main_game();
void board_initialization(char board[ROW][COL], int row, int col);
void board_printing(char board[ROW][COL], int row, int col);
