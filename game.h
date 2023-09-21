#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 11
#define COLS 11

#define ROW 9
#define COL 9

#define MINE_COUNT 10


//数组的初始化函数
void Init_board(char arr[ROWS][COLS], int rows, int cols, char set);

//打印棋盘
void Display_board(char arr[ROWS][COLS], int row, int col);

//布置地雷的函数
void Set_mine(char mine[ROWS][COLS], int row, int col);

//排查地雷
void Find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);