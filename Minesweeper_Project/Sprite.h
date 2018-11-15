#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <iostream>

class Sprite
{
private:
	SDL_Window* gWindow = NULL;
	SDL_Surface* gScreenSurface = NULL;
	SDL_Surface* gSpriteSurface = NULL;
	int Xpos, Ypos;
	int width, height;
	std::string path;
	bool isLoaded;
public:
	Sprite(std::string path);
	~Sprite();
	bool get_isLoaded();
	void apply(SDL_Surface* gScreenSurface);
protected:
};