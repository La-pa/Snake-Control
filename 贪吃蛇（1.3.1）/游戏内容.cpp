#include"declaration.h"


void GSnake_Map()
{
	for (int i = 0; i < 60; i += 2)
	{
		Gotoxy(i, 0);
		cout << "��";
		Gotoxy(i, 29);
		cout << "��";
	}
	for (int i = 0; i < 30; i++)
	{
		Gotoxy(0, i);
		cout << "��";
		Gotoxy(58, i);
		cout << "��";
	}

	food.x = 48;
	food.y = 20;
	Gotoxy(food.x, food.y);
	cout << "��";
	Gotoxy(78, 14);
	cout << score;
}


// 1.���ù��
void Gotoxy(int x, int y)
{
	COORD position = { x,y };
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hout, position);
}


//�ߵ�������Ϣ
void GSnake_Snake_()
{
	GSnake_Snake_Body();
	int  ch = RIGHT;

	while (Game_Snake_GameOver())
	{
		//����
		if (kbhit())
		{
			//fflush(stdin);//ˢ�»�����
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

//�ߵ�����
void GSnake_Snake_Body()
{
	//��ӡ��ͷ
	snake.len = 3;
	snake.x[0] = 20;
	snake.y[0] = 20;
	Gotoxy(snake.x[0], snake.y[0]);
	cout << "��";
	//��ӡ����
	for (int i = 1; i < snake.len; i++)
	{
		snake.x[i] = snake.x[i - 1];
		snake.y[i] = snake.y[i - 1] +1;
		Gotoxy(snake.x[i], snake.y[i]);
		cout << "��";
	}
}

void GSnake_Snake_Move(int direction)
{
	//����β��
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
	//����ͷ
	switch (direction)
	{
	case 72:snake.y[0]--; break;
	case 75:snake.x[0] -= 2; break;
	case 77:snake.x[0] += 2; break;
	case 80:snake.y[0]++; break;
	}
	Gotoxy(snake.x[0], snake.y[0]);
	cout << "��";
	changeflag = 1;


}


void GSnake_Food_Creat()
{
	if (snake.x[0] == food.x && snake.y[0] == food.y)//ֻ���߳Ե�ʳ�����������ʳ��
	{
		changeflag = 0;
		snake.len++;
		while (1)
		{
			srand((unsigned int)time(NULL));
			food.x = rand() % (60 - 6) + 2;//�޶�ʳ���x��Χ������Χǽ�������ܱ�֤food.xΪż��
			food.y = rand() % (30 - 2) + 1;
			for (int i = 0; i < snake.len; i++)
			{
				if (food.x == snake.x[i] && food.y == snake.y[i])//���������ʳ���������غ����˳�
					break;
			}
			if (food.x % 2 == 0)	break;//����Ҫ���˳�ѭ��
		}
		Gotoxy(78, 14);
		score += 50;
		cout << score ;
		Gotoxy(food.x, food.y);
		cout << "��";
	}

}

bool Game_Snake_GameOver()
{
	//����Χǽ��OVER
	if (snake.x[0] == 0 || snake.x[0] == 60 - 2)	return false;
	if (snake.y[0] == 0 || snake.y[0] == 30 - 1)	return false;
	for (int i = 1; i < snake.len; i++)
	{
		if (snake.x[0] == snake.x[i] && snake.y[0] == snake.y[i])
			return false;
	}
	return true;
}






