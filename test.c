#define _CRT_SECURE_NO_WARNINGS 1
//三子棋//一些想法和疑问1.提升电脑胜率，听过什么局势判别系统，考虑简单实现的想法
//电脑走棋时先进行判断，需要对自己下过的棋的位置储存，当能够形成赢的条件时会取消使用rand函数进行随机落子
//2.整段代码在判断结果时采用穷举的办法，这使得想改为n子棋后判断结果
//变得不容易，即使使用循环。
//3.收获，对rand函数的学习过程中顺带实现了猜数字的游戏，猜数字和三子棋
//都用到了把一个数字通过取模再加减的方式控制在特定的范围里，学到了
//4.输赢的标记符号和人类电脑的棋子设置成一样使得判断究竟是谁赢了变得简便。
//本身自己考虑的是假设都是人类先下，引入count变量来计算步数，当棋局判
//定结束时，再根据count奇偶性来决定谁赢。
//5.考虑到面向的玩家并不一定懂得数组从零开始，故要进行减一操作
//而电脑走棋时无需考虑，故直接生成随机数再取模就可，无需再调整
//6.在用iffull判断和棋时，参考代码对此函数的返回值使用了static修饰，why?






#include "game.h"

void menu()
{
	printf("********************************\n");
	printf("*********  1. play     *********\n");
	printf("*********  0. exit     *********\n");
	printf("********************************\n");
}

void game()
{
	char ret = 0;
	//存放下棋的数据
	char board[ROW][COL] = { 0 };
	//初始化棋盘为全空格
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//玩家下棋
		player_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断输赢
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑下棋
		computer_move(board, ROW, COL);//随机下棋
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢了\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}
	//DisplayBoard(board, ROW, COL);
}

//
//为了增强可读性，在这里给出结果标记符号
//玩家赢 - '*'
//电脑赢 - '#'
//平局   - 'Q'
//继续   - 'C'
//

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//游戏
			break;
		case 0:
			printf("退出游戏，去c楼通宵\n");
			break;
		default:
			printf("是不是在b楼迷路让你的小脑瓜都晕了，重新选择哟\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}