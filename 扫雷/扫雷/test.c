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
	char mine[ROWS][COLS] = { 0 };//布置雷的数组
	char show[ROWS][COLS] = { 0 };//排除雷的数组
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	SetMine(mine, ROW, COL);//布置雷
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
		printf("请选择：>");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
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