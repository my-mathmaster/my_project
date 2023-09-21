#include "game.h"

//�����ʼ��������ʵ��
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

//��ӡ����
void Display_board(char arr[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("-----------------\n");
	for (i = 0; i <= row; i++)
	{
		//��ӡ�к�
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);//��ӡ�к�
		for (j = 1; j <= col; j++)
		{
			printf("%c ", arr[i][j]);
		}
		printf("\n");
	}
}


//���õ��׺���
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



//ͳ���׵ĸ���
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


//�Ų����
void Find_mine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	while (count < row * col - MINE_COUNT)
	{
		printf("��������Ҫ�Ų�����꣺");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (mine[x][y] == '1')
			{
				printf("���ź����㱻ը���ˣ�\n");
				break;
			}
			else
			{
				count++;
				//Find_count��ͳ����Χ�׵ĸ����ĺ���
				int ret = Find_count(mine, x, y);
				show[x][y] = ret + '0';
				//����������ȷ���ٴ�ӡһ�����̣�������ҹ۲�
				Display_board(show, ROW, COL);
			}
		}
		else
		{
			printf("��������������������룡\n");
		}
	}
	if (count == row * col - MINE_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ���\n");
	}
}