#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("*****************************************\n");
	printf("*************  1. play  *****************\n");
	printf("*************  0. exit  *****************\n");
	printf("*****************************************\n");

}
void game()
{
	char mine[ROWS][COLS] = { 0 };//�����׵�����
	char show[ROWS][COLS] = { 0 };//�ų��׵�����
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	SetMine(mine, ROW, COL);//������
	PrintBoard(show, ROW, COL);
	FindMine(mine, show, ROW, COL);

}
void test()
{
	int num = 0;
	srand((unsigned int)time(NULL));
	do 
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	}while (num);
}
int main()
{
	char arr[ROWS][COLS] = { 0 };
	test();
	return 0;
}