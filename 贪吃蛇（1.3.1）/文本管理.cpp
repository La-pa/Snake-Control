#include"declaration.h"

void GSnake_Rule()
{
	system("cls");
	Gotoxy(40,12);
	cout << "����ʩ����";
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
	cout << "��߷�";
	Gotoxy(42, 15);
	printf("%d", max);
	
	Gotoxy(42, 20); cout << "1.�������˵�";
	
	int ch;
	while (1)
	{
		
		if(kbhit())
		{ 
			ch = getch();
			//ch = getch();
			switch (ch)
			{
			case'1':Game_Snake_Start(); break;
			default:Gotoxy(42, 29); cout << "����������"; break;
				break;
			}
		}
	}
}

int GSnake_MaxScoreInput()
{
	int Max = 0;
	FILE* fp;
	fp = fopen("Max Score.txt", "r");
	if (fp == NULL)
	{
		printf("Fail to open the file!");
		exit(0);
	}
	fscanf(fp, "%d", &Max);
	//Gotoxy(1, 1);
	//cout << Max;
	fclose(fp);

	return Max;
}

void GSnake_MaxScoreOutput(int max)
{
	FILE* fp;
	fp = fopen("Max Score.txt", "w");
	if (fp == NULL)
	{
		printf("Fail to open the file!");
		exit(0);
	}
	fprintf(fp, "%d", max);
	fclose(fp);
}

