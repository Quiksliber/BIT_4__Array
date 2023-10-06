#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("输入区 : ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
		{
			printf("即将正式进入游戏 !\n");
			printf("Loading...");
			Sleep(4000);
			system("cls");
			main_game();
			break;
		}
		case 0:
		{
			break;
		}
		default:
		{
			printf("ERROR!!!\n");
			break;
		}
		}
	} while (input);
	return 0;
}
