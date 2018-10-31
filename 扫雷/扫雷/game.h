#ifndef __GAME_H__
#define __GAME_H__

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>


#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define COUNT 10

void InitBoard(char board[ROWS][COLS],int row,int col, char ch);
void SetMine(char board[ROWS][COLS], int row, int col);
void PrintBoard(char board[ROWS][COLS], int row, int col);
void FirstFind(char mine[ROWS][COLS], int x, int y);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int Count_Mine(char mine[ROWS][COLS],int x,int y);
void clearing(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);


#endif //__GAME_H__

