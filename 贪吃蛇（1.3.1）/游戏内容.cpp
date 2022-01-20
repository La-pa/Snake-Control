#include"declaration.h"


void GSnake_Map()
{
	for (int i = 0; i < 60; i += 2)
	{
		Gotoxy(i, 0);
		cout << "■";
		Gotoxy(i, 29);
		cout << "■";
	}
	for (int i = 0; i < 30; i++)
	{
		Gotoxy(0, i);
		cout << "■";
		Gotoxy(58, i);
		cout << "■";
	}

	food.x = 48;
	food.y = 20;
	Gotoxy(food.x, food.y);
	cout << "●";
	Gotoxy(78, 14);
	cout << score;
}


// 1.设置光标
void Gotoxy(int x, int y)
{
	COORD position = { x,y };
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, position);
}


//蛇的所有信息
void GSnake_Snake_()
{
	GSnake_Snake_Body();
	int  ch = RIGHT;

	while (Game_Snake_GameOver())
	{
		//方向
		if (kbhit())
		{
			//fflush(stdin);//刷新缓存区
			ch = getch();
			ch = getch();
			switch (ch)
			{
			case 77:	direction = 77; break;
			case 75:	direction = 75; break;
			case 72:	direction = 72; break;
			case 80:	direction = 80; break;
			}
			if (history_direction == 72 && direction == 80)	direction = 72;
			if (history_direction == 80 && direction == 72)	direction = 80;
			if (history_direction == 75 && direction == 77)	direction = 75;
			if (history_direction == 77 && direction == 75)	direction = 77;
		}
		GSnake_Snake_Move(direction);
		GSnake_Food_Creat();
		Sleep(200);
	}
}

//蛇的身体
void GSnake_Snake_Body()
{
	//打印蛇头
	snake.len = 3;
	snake.x[0] = 20;
	snake.y[0] = 20;
	Gotoxy(snake.x[0], snake.y[0]);
	cout << "■";
	//打印蛇身
	for (int i = 1; i < snake.len; i++)
	{
		snake.x[i] = snake.x[i - 1];
		snake.y[i] = snake.y[i - 1] +1;
		Gotoxy(snake.x[i], snake.y[i]);
		cout << "■";
	}
}

void GSnake_Snake_Move(int direction)
{
	//消除尾巴
	if (changeflag == 1)
	{
		Gotoxy(snake.x[snake.len - 1], snake.y[snake.len - 1]);
		cout << "  ";
	}


	for (int i = snake.len - 1; i > 0; i--)
	{
		snake.x[i] = snake.x[i - 1];
		snake.y[i] = snake.y[i - 1];
	}

	history_direction = direction;
	//增加头
	switch (direction)
	{
	case 72:snake.y[0]--; break;
	case 75:snake.x[0] -= 2; break;
	case 77:snake.x[0] += 2; break;
	case 80:snake.y[0]++; break;
	}
	Gotoxy(snake.x[0], snake.y[0]);
	cout << "■";
	changeflag = 1;


}


void GSnake_Food_Creat()
{
	if (snake.x[0] == food.x && snake.y[0] == food.y)//只有蛇吃到食物，才能生成新食物
	{
		changeflag = 0;
		snake.len++;
		while (1)
		{
			srand((unsigned int)time(NULL));
			food.x = rand() % (60 - 6) + 2;//限定食物的x范围不超出围墙，但不能保证food.x为偶数
			food.y = rand() % (30 - 2) + 1;
			for (int i = 0; i < snake.len; i++)
			{
				if (food.x == snake.x[i] && food.y == snake.y[i])//如果产生的食物与蛇身重合则退出
					break;
			}
			if (food.x % 2 == 0)	break;//符合要求，退出循环
		}
		Gotoxy(78, 14);
		score += 50;
		cout << score ;
		Gotoxy(food.x, food.y);
		cout << "●";
	}

}

bool Game_Snake_GameOver()
{
	//碰到围墙，OVER
	if (snake.x[0] == 0 || snake.x[0] == 60 - 2)	return false;
	if (snake.y[0] == 0 || snake.y[0] == 30 - 1)	return false;
	for (int i = 1; i < snake.len; i++)
	{
		if (snake.x[0] == snake.x[i] && snake.y[0] == snake.y[i])
			return false;
	}
	return true;
}






