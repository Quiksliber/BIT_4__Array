#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void main_game()
{
	char mine[ROWS][COLS] = { 0 };//��ʾ���úõ��ס�
	char show[ROWS][COLS] = { 0 };//��ʾ�Ų���׵ĸ�����
	
	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//��ӡһ������
	DisplayBoard(show, ROW, COL);

	//�Ȳ��ף�������
	SetMine(mine, ROW, COL);
	FindMine(mine, show, ROW, COL);
}