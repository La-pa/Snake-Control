#include"declaration.h"



// 1.游戏开始界面
void Game_Snake_Start()
{
	system("mode con cols=100 lines=30");
	int score = 0;
	Gotoxy(42, 15);
	cout << "1.开始游戏" ;
	Gotoxy(42, 17);
	cout << "2.游戏规则" ;
	Gotoxy(42, 19);
	cout << "3.退出游戏" ;

	char option = '1';
	L1:
	option = getch();
	switch(option)
	{
	case '1':Game_Snake_ing(); break;
	case '2':GSnake_Rule(); break;
	case '3':break;
	default: Gotoxy(0, 29); cout << "请重新输入"; goto L1;
	}
	return;
}


// 2.游戏进行界面
void Game_Snake_ing()
{
	//界面
	system("cls");//清空界面
	GSnake_Map();

	direction = RIGHT;
	history_direction = RIGHT;

	//得分
	Gotoxy(72, 14);
	cout << "分数: ";

	//蛇
	GSnake_Snake_();

	//游戏结束
	Game_Snake_Over();

	Gotoxy(30, 30);
	//cout << '\n';
	//system("pause");
}


// 3.游戏结束界面
void Game_Snake_Over()
{
	//结束界面绘画
	system("cls");
	Gotoxy(game_over_x, game_over_y);
	cout << "游戏结束";
	Gotoxy(game_over_x, game_over_y + 2);
	cout << "您的成绩：";
	Gotoxy(game_over_x, game_over_y + 4);
	cout << "分数: " << score;

	//其他操作
	Gotoxy(game_over_x - 2, game_over_y + 9);
	cout << "1.重新游戏";
	Gotoxy(game_over_x - 2, game_over_y + 10);
	cout << "2.返回主菜单";

	char option;
	L1:
	option = getch();
	switch (option)
	{
	case '1':Game_Snake_ing(); break;
	case '2':Game_Snake_Start(); break;
	default:Gotoxy(0, 29); cout << "请重新输入"; goto L1;
	}
 }


