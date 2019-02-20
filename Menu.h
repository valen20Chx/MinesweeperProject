#pragma once

#include "Game.h"
#include "Object.h"
#include "Text.h"
#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

class Menu
{
private:
	Object btnPlay;
	

public:
	Menu();
	~Menu();
	void createPlay(int destX, int destY);
};