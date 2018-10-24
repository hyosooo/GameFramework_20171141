#include "Monster.h"
#include <SDL_image.h>
#include <iostream>
using namespace std;

void Monster::update()
{
	if (m_x > 400)
	{
		speed2 = -speed;
	}
	else if (m_x < 100)
	{
		speed2 = speed;
	}

	m_x += speed2;
	m_currentFrame = int(((SDL_GetTicks()/ 100) % 6));
}

