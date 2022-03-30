#pragma once
#include<cstdio>
#include<cstdlib>
#include <iostream>
#include<Windows.h>
#include<control.h>
#include<conio.h>
#include<fstream>
//#include<graphics.h>
#include<time.h>	//有各种时间函数
#pragma comment (lib,"winmm.lib")

using namespace std;

//贪吃蛇
void Game_Snake();

const int UP = 72;
const int DOWN = 80;
const int LEFT = 75;
const int RIGHT = 77;

static int changeflag = 1;

// 一、游戏界面
void Game_Snake_Start();// 1.游戏开始界面
void Game_Snake_Over();// 2.游戏结束界面
void Game_Snake_ing();// 3.游戏进行界面


// 二、游戏说明(文字）
void GSnake_Rule();

//游戏结束
bool Game_Snake_GameOver();


void GSnake_Snake_();

//	a.蛇的身体
void GSnake_Snake_Body();
void GSnake_Snake_Move(int direction);

// 2.食物
void GSnake_Food_Creat();

// 3.地图
void GSnake_Map();

// 其他设置

// 1.设置光标
void Gotoxy(int x, int y);

//食物
struct
{
	int x;
	int y;
}food;

//蛇
struct
{
	int len;
	int x[200];//用来记录蛇身每个方块的坐标
	int y[200];
	/*int speed;*/
}snake;

//方向
extern int direction;
extern int history_direction;



extern int score ;

//结束界面位置
const int game_over_x = 46 ;
const int game_over_y = 12;

//游戏开始界面的背景图片
void Game_Snake_Start_Background();

//最高分（从txt文件导入解决方案）
int GSnake_MaxScoreInput();

//最高分界面
void GSnake_MaxScore();
