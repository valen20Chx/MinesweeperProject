#pragma once

#include <SDL.h>
#include <iostream>

class Renderer
{
private:
	SDL_Renderer* mRenderer;
public:
	Renderer(SDL_Window* mWindow);
	~Renderer();
	SDL_Renderer* get_mRenderer();
};

