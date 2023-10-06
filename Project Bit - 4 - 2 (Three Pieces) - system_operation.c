#include "game.h"

//Print the initial directory of the game
void menu()
{
printf("###########################################\n" );
Sleep(1000);
printf("######## Welcome to WEIJIACHEN OS! ########\n");
Sleep(1000);
printf("####### Please make a selection in the input area below: ######\n");
Sleep(1000);
printf("#### To officially enter the three-piece game, please enter 1; ####\n");
Sleep(1000);
printf("########### To exit now, please enter 0; ##########\n");
Sleep(1000);
printf("###########################################\n" );
}

//Initialization of the game board (can make the panel generous and beautiful)
void board_initialization(char board[ROW][COL], int row, int col)
{
int x = 0;
int y = 0;
for (x = 0; x < row; x++)
{
for (y = 0; y < col; y++)
{
board[x][y] = ' ';
}
}
}

//Print of game board
void board_printing(char board[ROW][COL], int row, int col)
{
int i = 0;
for (i = 0; i < row; i++)
{
int j = 0;
for (j = 0; j < col; j++)
{
printf(" %c ", board[i][j]);
if (j < col - 1)
{
printf("|");
}
}
printf("\n");
if (i < row - 1)
{
for (j = 0; j < col; j++)
{
printf("---");
if (j < col - 1)
{
printf("|");
}
}
}
printf("\n");
}
}

//Winning or losing judgment program
char win(char board[ROW][COL], int row, int col)
{
int x = 0;
int y = 0;

//Judge three lines
for (x = 0; x < row; x++)
{
for (y = 1; y < col - 1; y++)
{
if (board[x][y - 1] == board[x][y] && board[x][y] == board[x][y + 1] && board[x][y] != ' ')
{
if (board[x][y] == '*')
{
//Player wins
return 'P';
}
else if (board[x][y] == '$')
{
//computer wins
return 'S';
}
}
}
}

//Judge three columns
for (y = 0; y < col; y++)
{
for (x = 1; x < row - 1; x++)
{
if (board[x - 1][y] == board[x][y] && board[x][y] == board[x + 1][y] && board[x][y] != ' ')
{
if (board[x][y] == '*')
{
//Player wins
return 'P';
}
else if (board[x][y] == '$')
{
//computer wins
return 'S';
}
}
}
}

//Judge diagonal lines
for (x = 0, y = 0; x < row - 1, y < col - 1; x++, y++)
{
if (board[x - 1][y - 1] == board[x][y] && board[x][y] == board[x + 1][y + 1] && board[x][y ] != ' ')
{
{
if (board[x][y] == '*')
{
//Player wins
return 'P';
}
else if (board[x][y] == '$')
{
//computer wins
return 'S';
}
}
}
else if(board[x - 1][y + 1] == board[x][y] && board[x][y] == board[x + 1][y - 1] && board[x][ y] != ' ')
{
{
if (board[x][y] == '*')
{
//Player wins
return 'P';
}
else if (board[x][y] == '$')
{
//computer wins
return 'S';
}
}
}
}

//Judge a tie
for (x = 0; x < row; x++)
{
for (y = 0; y < col; y++)
{
if (board[x][y] == ' ')
{
//The board is not full
return 'C';
}
}
}
//The board is full, resulting in a tie.
return 'E';
}

//Print the winning and losing results
void winner_printing(char outcome)
{
if (outcome == 'P')
{
printf("Player wins!\n");
}
else if (outcome == 'S')
{
printf("Computer wins!\n");
}
else if (outcome == 'E')
{
printf("Tie!\n");
}
else
{
printf("ERROR!!!");
}
}
