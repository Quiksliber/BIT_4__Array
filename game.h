#pragma once

//ͷ�ļ��İ���
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

//���ŵĶ���
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define easy_mine 10

//��Ϸ�����ĺ���������
void menu();//Ŀ¼�˵�
void main_game();//����Ϸ
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//���̵ĳ�ʼ��
void DisplayBoard(char board[ROWS][COLS], int row, int col);//���̵Ĵ�ӡ
void SetMine(char board[ROWS][COLS], int row, int col);//���׵ĺ���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//���׵ĺ���
int GetMineCount(char mine[ROWS][COLS], int x, int y);
