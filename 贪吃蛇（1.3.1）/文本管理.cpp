#include"declaration.h"

void GSnake_Rule()
{
	system("cls");
	Gotoxy(40,12);
	cout << "正在施工中";
	Gotoxy(40, 13);
	system("pause");
	Game_Snake_Start();
}

void GSnake_MaxScore()
{
	system("cls");
	int max = 0;
	max = GSnake_MaxScoreInput();
	Gotoxy(42, 10);
	cout << "最高分";
	Gotoxy(42, 15);
	printf("%d", max);
	
	Gotoxy(42, 20); cout << "1.返回主菜单";
	
	int ch;
	while (1)
	{
		
		if(kbhit())
		{ 
			ch = getch();
			ch = getch();
			switch (ch)
			{
			case'1':Game_Snake_Start(); break;
			default:Gotoxy(42, 29); cout << "请重新输入"; break;
				break;
			}
		}
	}
}

int GSnake_MaxScoreInput()
{
	int Max;
	FILE* fp;
	fp = fopen("Max Score.txt", "r");
	Max = fscanf(fp, "%d", &Max);	

	fclose(fp);

	return Max;
}

