#include "game.h"
//����ʱ��ԭ�����ҵĽǶȻ������Ż��Ŀռ���1.��һ���Ų�ʱ���ᱻը��
//2���������걾�����ۣ�����Χ�˸�����Ҳ����û�׵�����ʱ����ʵ��չ����ò�ƿ����ú����ݹ飿
//3.û��ʵ�ֱ�ǹ���
//�ջ�1.�ڼ�����Χ�����Ƿ�����ʱ�����ַ������ּӼ����ܺ���ʵ��ȷʵû�뵽�������ǵ�������Χ�˸�����
//��'1'���бȽ�  2.��ȻҪ����9*9�ģ�����������11*11����ֹ���ڼ�����Χ����Ŀʱ�߽����ӳ���Խ��
//���ʵ����






void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//��������ĳ�ʼ��
	//mine����Ԫ��ȫ����ʼ��Ϊ�ַ�0
	//show����Ԫ��ȫ����ʼ��Ϊ�ַ�*
	Init_board(mine, ROWS, COLS, '0');
	Init_board(show, ROWS, COLS, '*');


	//��ӡ����,�Ա�����ҿ��������ѡ����Ӧ��λ�ö�Ӧ������
	Display_board(show, ROW, COL);


	//���õ���
	Set_mine(mine, ROW, COL);

	//�Ų����
	Find_mine(mine, show, ROW, COL);
	//�������鶼��������Ϊ�Ų�ʱ��������Ԫ�ض�������Ӧ�ĸı�
	//�Ų�������ٴ�ӡһ�ε������̣������չʾ���׵�λ��
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
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳�ɨ�ף�\n");
			break;
		default:
			printf("����������������룡\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}