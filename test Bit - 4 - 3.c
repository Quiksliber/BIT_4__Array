#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("������ : ");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			break;
		case 1:
			printf("������ʽ������Ϸ !\n");
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

//ע������
  //1.�Ż���Ŀ��
    //��1������õ㲻��������Χû���ף���չ��һƬ���꣨�����ݹ�ʵ�֣�
    //��2�����Ѿ�ȷ�����׵ĵ���б�ע