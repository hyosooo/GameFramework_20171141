#pragma once
#include "SDL.h"
#include <map>
#include "GameObject.h"

class Monster : public GameObject
{
public:

	void update();

private:
	int speed2;
};