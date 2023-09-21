#include "game.h"
//由于时间原因，以我的角度还可以优化的空间有1.第一次排查时不会被炸死
//2当满足坐标本身不是累，且周围八个坐标也存在没雷的坐标时可以实现展开，貌似可以用函数递归？
//3.没有实现标记功能
//收获：1.在计算周围坐标是否有雷时，用字符型数字加减算总和来实现确实没想到，本身考虑的是拿周围八个坐标
//与'1'进行比较  2.虽然要的是9*9的，但是引入了11*11，防止了在计算周围雷数目时边界棋子出现越界
//访问的情况






void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//两个数组的初始化
	//mine数组元素全部初始化为字符0
	//show数组元素全部初始化为字符*
	Init_board(mine, ROWS, COLS, '0');
	Init_board(show, ROWS, COLS, '*');


	//打印棋盘,以便让玩家可以清楚的选择相应的位置对应的坐标
	Display_board(show, ROW, COL);


	//布置地雷
	Set_mine(mine, ROW, COL);

	//排查地雷
	Find_mine(mine, show, ROW, COL);
	//两个数组都传入是因为排查时两个数组元素都会有相应的改变
	//排查结束，再打印一次地雷棋盘，向玩家展示地雷的位置
	Display_board(mine, ROW, COL);
}


void menu()
{
	printf("*******************************\n");
	printf("*********  1. play  ***********\n");
	printf("*********  0. exit  ***********\n");
	printf("*******************************\n");
}


void test()
{
	int input = 0;
	do
	{
		menu();
		srand((unsigned int)time(NULL));
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出扫雷！\n");
			break;
		default:
			printf("输入错误，请重新输入！\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}