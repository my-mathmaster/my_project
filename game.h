#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 11
#define COLS 11

#define ROW 9
#define COL 9

#define MINE_COUNT 10


//����ĳ�ʼ������
void Init_board(char arr[ROWS][COLS], int rows, int cols, char set);

//��ӡ����
void Display_board(char arr[ROWS][COLS], int row, int col);

//���õ��׵ĺ���
void Set_mine(char mine[ROWS][COLS], int row, int col);

//�Ų����
void Find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);