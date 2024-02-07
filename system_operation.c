#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

//��Ϸ��ʼĿ¼�Ĵ�ӡ
void menu()
{
	printf("############################################\n");
	Sleep(1000);
	printf("########  ��ӭ���� WEIJIACHEN OS !  ########\n");
	Sleep(1000);
	printf("#######  ���������������������ѡ�� ######\n");
	Sleep(1000);
	printf("#####  Ҫ��ʽ����ɨ����Ϸ�������� 1 �� #####\n");
	Sleep(1000);
	printf("###########  �����˳��������� 0 ��##########\n");
	Sleep(1000);
	printf("############################################\n");
}

//���̰���ĳ�ʼ��
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

//���̰���Ĵ�ӡ
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-----------------\n");
	for (i = 0; i <= col; i++)//��ӡ�к�
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//��ӡ�к�
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-----------------\n");
}

//���׵ĺ���
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = easy_mine;//����ʮ���׵ļ�������
	while (count)
	{
		//��������±�
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

//����������Χ�׵ĸ���
int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	int i = 0;
	int j = 0;
	int sum = 0;
	for (i = -1; i <= 1; i++)
	{
		for (j = -1; j <= 1; j++)
		{
			sum = sum + mine[x + i][y + j] - '0';
		}
	}
	return sum;
}

//���׵ĺ���
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int empty = 0;
	while (empty < row * col - easy_mine)
	{
		//�����Ų�����
		printf("������Ҫ�Ų������ : \n");
		printf("������ : ");
		scanf("%d", &y);
		printf("������ : ");
		scanf("%d", &x);
		printf("\n");
		//�ж�����Ϸ���
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//������괦�Ƿ�Ϊ��
			//��1�����ף�ը������Ϸ����
			if (mine[x][y] == '1')
			{
				printf("���ź�������ը����~\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			//��2�������ף�ͳ��������Χ�м����ף��洢�Ų���Ϣ�� show ���飬��Ϸ����
			else
			{
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
			}
		}
		else
		{
			printf("�����������������\n");
		}
	}
	if (empty == row * col - easy_mine)
	{
		printf("��ϲ����Ϸ���� ! ");
		DisplayBoard(mine, ROW, COL);
	}
}