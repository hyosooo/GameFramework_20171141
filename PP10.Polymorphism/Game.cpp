#include "Game.h"
#include <SDL_image.h>
#include <iostream>
#include"TextureManager.h"
#include "Enemy.h"
#include "Monster.h"
#include "GameObject.h"
using namespace std;

bool Game::init(const char* title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		m_bRunning = true;

		// load �κ� ��ġ   
		if (!TheTextureManager::Instance()->load("assets/animate-alpha.png", "animate", m_pRenderer))
		{
			return false;
		}

		if (!TheTextureManager::Instance()->load("assets/monster.png", "monster", m_pRenderer))
		{
			return false;
		}

		m_go = new GameObject();
		m_player = new Player();
		m_enemy = new Enemy();
		m_monster = new Monster();
		m_monster2 = new Monster();


		m_go->load(100, 100, 128, 82, "animate");
		m_player->load(300, 300, 128, 82, "animate");
		m_enemy->load(0, 0, 128, 82, "animate");
		m_monster->load(30, 100, 97, 70, "monster");
		m_monster2->load(30, 250, 97, 70, "monster");

		m_gameObjects.push_back(m_go);
		m_gameObjects.push_back(m_player);
		m_gameObjects.push_back(m_enemy);
		m_gameObjects.push_back(m_monster);
		m_gameObjects.push_back(m_monster2);
		
		m_monster->SetSpeed(1);
		m_monster2->SetSpeed(3);
	}

	else {
		return false; // sdl could not initialize
	}
	return true;
}

void Game::render()
{
	SDL_RenderClear(m_pRenderer); // clear to the draw colour
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->draw(m_pRenderer);
	}
	SDL_RenderPresent(m_pRenderer); // draw to the screen
}
void Game::update()
{
	for (std::vector<GameObject*>::size_type i = 0;
		i != m_gameObjects.size(); i++)
	{
		m_gameObjects[i]->update();
	}

	


}

void Game::clean()
{
	std::cout << "cleaning game" << endl;
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}
