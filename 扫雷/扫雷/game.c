#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void InitBoard(char board[ROWS][COLS], int row, int col, char ch)
{
	memset(board, ch, row*col*sizeof(board[0][0]));
}
void SetMine(char board[ROWS][COLS], int row, int col)
{
	srand((unsigned int)time(NULL));
	int count = COUNT;
	while (count)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
void PrintBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("   ");
	for (i = 1; i <= row; i++)
	{
		printf(" %d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf(" %d ", i);
		for (j = 1; j <= col; j++)
		{  
			
			printf(" %c ", board[i][j]);
		}
		printf("\n");
	}
}
int Count_Mine(char mine[ROWS][COLS], int x, int y)
{

	return (mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1]) - 8 * '0';
}
void FirstFind(char mine[ROWS][COLS], int x, int y)
{
	int a = 0;
	int b = 0;
	if (mine[x][y] == '1')
	{
		mine[x][y] = '0';
		while (1)
		{
			a = rand() % 9 + 1;
			b = rand() % 9 + 1;
			if (mine[a][b] != '1')
			{
				mine[a][b] = '0';
				break;
			}
		}
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int w = 0;
	while (w<row*col-COUNT)
	{
		printf("请输入坐标：");
		scanf("%d%d", &x, &y);
		if (w == 0)
		{
			FirstFind(mine,x,y);
		}
		if ((x >= 0 && x <= row) && (y >= 0 && y <= col))
		{
			if (mine[x][y] == '1')
			{
				printf("你被炸死了\n");
				PrintBoard(mine, ROW, COL);
				break;
			}
			else
			{
				int count = Count_Mine(mine, x, y);
				show[x][y] = count+'0';
				clearing(mine, show, x, y);
				PrintBoard(show, ROW, COL);
				w++;

			}
		}
		else printf("坐标无效\n");
	}
	if(w==row*col-COUNT)
	{
		printf("恭喜你，扫雷成功！\n");
		PrintBoard(mine, ROW, COL);

	}
}
void clearing(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{

	if (0 == Count_Mine(mine, x, y))
	{
		show[x][y] = ' ';
		if ((x - 1)>0 && (y - 1)>0 && show[x - 1][y - 1] == '*')
			clearing(mine, show, x - 1, y - 1);

		if ((y - 1)>0 && show[x][y - 1] == '*')
			clearing(mine, show, x - 1, y - 1);

		if ((x + 1) <= ROW && (y - 1)>0 && show[x + 1][y - 1] == '*')
			clearing(mine, show, x + 1, y - 1);

		if ((x + 1) <= ROW && show[x + 1][y] == '*')
			clearing(mine, show, x + 1, y);

		if ((x + 1) <= ROW && (y + 1) <= COL && show[x + 1][y + 1] == '*')
			clearing(mine, show, x + 1, y + 1);

		if ((y + 1) <= COL && show[x][y + 1] == '*')
			clearing(mine, show, x, y + 1);

		if ((x - 1)>0 && (y + 1) <= COL && show[x - 1][y + 1] == '*')
			clearing(mine, show, x - 1, y + 1);

		if ((x - 1)>0 && show[x - 1][y] == '*')
			clearing(mine, show, x - 1, y);

	}
	else
		show[x][y] = Count_Mine(mine, x, y) + '0';
}



