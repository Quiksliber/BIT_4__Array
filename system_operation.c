#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

//游戏初始目录的打印
void menu()
{
	printf("############################################\n");
	Sleep(1000);
	printf("########  欢迎进入 WEIJIACHEN OS !  ########\n");
	Sleep(1000);
	printf("#######  请在下面的输入区域做出选择： ######\n");
	Sleep(1000);
	printf("#####  要正式进入扫雷游戏，请输入 1 ； #####\n");
	Sleep(1000);
	printf("###########  现在退出，请输入 0 ；##########\n");
	Sleep(1000);
	printf("############################################\n");
}

//棋盘板面的初始化
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

//棋盘板面的打印
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-----------------\n");
	for (i = 0; i <= col; i++)//打印列号
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//打印行号
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("-----------------\n");
}

//布雷的函数
void SetMine(char mine[ROWS][COLS], int row, int col)
{
	int count = easy_mine;//布置十个雷的计数函数
	while (count)
	{
		//生成随机下标
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

//计算坐标周围雷的个数
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

//排雷的函数
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int empty = 0;
	while (empty < row * col - easy_mine)
	{
		//输入排查坐标
		printf("请输入要排查的坐标 : \n");
		printf("横坐标 : ");
		scanf("%d", &y);
		printf("纵坐标 : ");
		scanf("%d", &x);
		printf("\n");
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//检查坐标处是否为雷
			//（1）是雷，炸死，游戏结束
			if (mine[x][y] == '1')
			{
				printf("很遗憾，您被炸死了~\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			//（2）不是雷，统计坐标周围有几个雷，存储排查信息到 show 数组，游戏继续
			else
			{
				int count = GetMineCount(mine, x, y);
				show[x][y] = count + '0';
				DisplayBoard(show, ROW, COL);
			}
		}
		else
		{
			printf("坐标错误，请重新输入\n");
		}
	}
	if (empty == row * col - easy_mine)
	{
		printf("恭喜，游戏结束 ! ");
		DisplayBoard(mine, ROW, COL);
	}
}