#include"declaration.h"

//全局变量
int score = 0;
int direction = RIGHT;
int history_direction = RIGHT;

int main()
{
	Game_Snake();
	return 0;
}

//●

//贪吃蛇游戏
void Game_Snake()
{

	Game_Snake_Start();
	/*Game_Snake_ing();
	Game_Snake_Over();*/
}