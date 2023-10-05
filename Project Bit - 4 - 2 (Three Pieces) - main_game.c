#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

char board[ROW][COL];

void player_moving()
{
	int x = 0;
	int y = 0;
	printf("Now it's your turn to play chess.");
	while (1)
	{
		printf("Please enter your placement position :");
		scanf("%d %d", &x, &y);

		//legality judgment
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			//Before placing the stone, check whether the square is occupied
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("This position is occupied, please check your placement.");
			}
		}
		else
		{
			printf("The coordinates are out of bounds, please re-enter.");
		}
	}
}

void system_moving()
{
	printf("The computer is currently playing chess.\n");
	while (1)
	{
		int x = rand() % ROW;
		int y = rand() % COL;
		if (board[x][y] == ' ')
		{
			board[x][y] = '$';
			break;
		}
	}
}

void main_game()
{
	//Initialization of the chessboard
	board_initialization(board, ROW, COL);

	//Chessboard printing
	board_printing(board, ROW, COL);

	//Formal game operation
	while (1)
	{
		player_moving();
		system("cls");
		board_printing(board, ROW, COL);
		system_moving();
		board_printing(board, ROW, COL);
	}
	
}
