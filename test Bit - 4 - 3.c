#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("输入区 : ");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			break;
		case 1:
			printf("即将正式进入游戏 !\n");
			printf("Loading...");
			Sleep(4000);
			system("cls");
			main_game();
			break;
		default:
			printf("ERROR!!!\n");
			break;
		}
	} while (input);
	return 0;
}

//注释区：
  //1.优化项目：
    //（1）如果该点不是雷且周围没有雷，则展开一片坐标（函数递归实现）
    //（2）对已经确定是雷的点进行标注