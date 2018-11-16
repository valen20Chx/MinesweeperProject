#pragma once

#include <SDL.h>
#include <string>
#include <iostream>

class Sprite
{
private:
	SDL_Window* gWindow;
	SDL_Surface* gScreenSurface;
	SDL_Surface* gSpriteSurface;
	int Xpos, Ypos;
	int width, height;
	std::string path;
	bool isLoaded;
public:
	Sprite(std::string path);
	~Sprite();
	void apply(SDL_Surface* gScreenSurface);
	bool get_isLoaded();
	SDL_Surface* get_Surface();
protected:
};