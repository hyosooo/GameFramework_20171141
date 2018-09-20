#include"Game.h"
#include <iostream>
using namespace std;

Gamee*g_game = 0;

int main(int argc, char*argv[])
{
	g_game = new Gamee();
	g_game->init("Chapter 1", 100, 100, 640, 480, false);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}SDL_Delay(10000);
	g_game->clean();

	return 0;
}