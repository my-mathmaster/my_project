#include "game.h"

//数组初始化函数的实现
void Init_board(char arr[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			arr[i][j] = set;
		}
	}
}

//打印棋盘
void Display_board(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-----------------\n");
	for (i = 0; i <= row; i++)
	{
		//打印列号
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//打印行号
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}


//布置地雷函数
void Set_mine(char mine[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int ret = MINE_COUNT;
	while (ret)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			ret--;
		}
	}
}



//统计雷的个数
int Find_count(char mine[ROWS][COLS], int x, int y)
{
	return mine[x + 1][y - 1] +
		mine[x][y - 1] +
		mine[x - 1][y - 1] +
		mine[x + 1][y] +
		mine[x - 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1] - 8 * '0';
}


//排查地雷
void Find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	while (count < row * col - MINE_COUNT)
	{
		printf("请输入想要排查的坐标：");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了！\n");
				break;
			}
			else
			{
				count++;
				//Find_count是统计周围雷的个数的函数
				int ret = Find_count(mine, x, y);
				show[x][y] = ret + '0';
				//输入坐标正确后，再打印一次棋盘，方便玩家观察
				Display_board(show, ROW, COL);
			}
		}
		else
		{
			printf("坐标输入错误，请重新输入！\n");
		}
	}
	if (count == row * col - MINE_COUNT)
	{
		printf("恭喜你，排雷成功！\n");
	}
}