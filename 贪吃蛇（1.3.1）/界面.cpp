#include"declaration.h"



// 1.��Ϸ��ʼ����
void Game_Snake_Start()
{
	system("mode con cols=100 lines=30");
	int score = 0;
	Gotoxy(42, 15);
	cout << "1.��ʼ��Ϸ" ;
	Gotoxy(42, 17);
	cout << "2.��Ϸ����" ;
	Gotoxy(42, 19);
	cout << "3.�˳���Ϸ" ;

	char option = '1';
	L1:
	option = getch();
	switch(option)
	{
	case '1':Game_Snake_ing(); break;
	case '2':GSnake_Rule(); break;
	case '3':break;
	default: Gotoxy(0, 29); cout << "����������"; goto L1;
	}
	return;
}


// 2.��Ϸ���н���
void Game_Snake_ing()
{
	//����
	system("cls");//��ս���
	GSnake_Map();

	direction = RIGHT;
	history_direction = RIGHT;

	//�÷�
	Gotoxy(72, 14);
	cout << "����: ";

	//��
	GSnake_Snake_();

	//��Ϸ����
	Game_Snake_Over();

	Gotoxy(30, 30);
	//cout << '\n';
	//system("pause");
}


// 3.��Ϸ��������
void Game_Snake_Over()
{
	//��������滭
	system("cls");
	Gotoxy(game_over_x, game_over_y);
	cout << "��Ϸ����";
	Gotoxy(game_over_x, game_over_y + 2);
	cout << "���ĳɼ���";
	Gotoxy(game_over_x, game_over_y + 4);
	cout << "����: " << score;

	//��������
	Gotoxy(game_over_x - 2, game_over_y + 9);
	cout << "1.������Ϸ";
	Gotoxy(game_over_x - 2, game_over_y + 10);
	cout << "2.�������˵�";

	char option;
	L1:
	option = getch();
	switch (option)
	{
	case '1':Game_Snake_ing(); break;
	case '2':Game_Snake_Start(); break;
	default:Gotoxy(0, 29); cout << "����������"; goto L1;
	}
 }


