#define _CRT_SECURE_NO_WARNINGS 1
//������//һЩ�뷨������1.��������ʤ�ʣ�����ʲô�����б�ϵͳ�����Ǽ�ʵ�ֵ��뷨
//��������ʱ�Ƚ����жϣ���Ҫ���Լ��¹������λ�ô��棬���ܹ��γ�Ӯ������ʱ��ȡ��ʹ��rand���������������
//2.���δ������жϽ��ʱ������ٵİ취����ʹ�����Ϊn������жϽ��
//��ò����ף���ʹʹ��ѭ����
//3.�ջ񣬶�rand������ѧϰ������˳��ʵ���˲����ֵ���Ϸ�������ֺ�������
//���õ��˰�һ������ͨ��ȡģ�ټӼ��ķ�ʽ�������ض��ķ�Χ�ѧ����
//4.��Ӯ�ı�Ƿ��ź�������Ե��������ó�һ��ʹ���жϾ�����˭Ӯ�˱�ü�㡣
//�����Լ����ǵ��Ǽ��趼���������£�����count���������㲽�����������
//������ʱ���ٸ���count��ż��������˭Ӯ��
//5.���ǵ��������Ҳ���һ������������㿪ʼ����Ҫ���м�һ����
//����������ʱ���迼�ǣ���ֱ�������������ȡģ�Ϳɣ������ٵ���
//6.����iffull�жϺ���ʱ���ο�����Դ˺����ķ���ֵʹ����static���Σ�why?






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
	//������������
	char board[ROW][COL] = { 0 };
	//��ʼ������Ϊȫ�ո�
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//�������
		player_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж���Ӯ
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//��������
		computer_move(board, ROW, COL);//�������
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ��\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
	//DisplayBoard(board, ROW, COL);
}

//
//Ϊ����ǿ�ɶ��ԣ���������������Ƿ���
//���Ӯ - '*'
//����Ӯ - '#'
//ƽ��   - 'Q'
//����   - 'C'
//

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();//��Ϸ
			break;
		case 0:
			printf("�˳���Ϸ��ȥc¥ͨ��\n");
			break;
		default:
			printf("�ǲ�����b¥��·�����С�Թ϶����ˣ�����ѡ��Ӵ\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}