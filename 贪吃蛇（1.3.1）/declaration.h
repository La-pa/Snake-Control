#pragma once
#include<cstdio>
#include<cstdlib>
#include <iostream>
#include<Windows.h>
#include<control.h>
#include<conio.h>
#include<fstream>
//#include<graphics.h>
#include<time.h>	//�и���ʱ�亯��
#pragma comment (lib,"winmm.lib")

using namespace std;

//̰����
void Game_Snake();

const int UP = 72;
const int DOWN = 80;
const int LEFT = 75;
const int RIGHT = 77;

static int changeflag = 1;

// һ����Ϸ����
void Game_Snake_Start();// 1.��Ϸ��ʼ����
void Game_Snake_Over();// 2.��Ϸ��������
void Game_Snake_ing();// 3.��Ϸ���н���


// ������Ϸ˵��(���֣�
void GSnake_Rule();

//��Ϸ����
bool Game_Snake_GameOver();


void GSnake_Snake_();

//	a.�ߵ�����
void GSnake_Snake_Body();
void GSnake_Snake_Move(int direction);

// 2.ʳ��
void GSnake_Food_Creat();

// 3.��ͼ
void GSnake_Map();

// ��������

// 1.���ù��
void Gotoxy(int x, int y);

//ʳ��
struct
{
	int x;
	int y;
}food;

//��
struct
{
	int len;
	int x[200];//������¼����ÿ�����������
	int y[200];
	/*int speed;*/
}snake;

//����
extern int direction;
extern int history_direction;



extern int score ;

//��������λ��
const int game_over_x = 46 ;
const int game_over_y = 12;

//��Ϸ��ʼ����ı���ͼƬ
void Game_Snake_Start_Background();

//��߷֣���txt�ļ�������������
int GSnake_MaxScoreInput();

//��߷ֽ���
void GSnake_MaxScore();
