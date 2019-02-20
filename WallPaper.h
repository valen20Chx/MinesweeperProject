#pragma once

#include <string>
#include <iostream>

#include "SDL.h"
#include "SDL_image.h"

class WallPaper
{
private:
	int imgWidth;
	int imgHeight;
	int screenWidth;
	int screenHeight;
	std::string path;
	SDL_Renderer* wRenderer;
	SDL_Texture* mTexture;
	SDL_Surface* mSurface;
public:
	WallPaper(int imgWidth, int imgHeight, int screenWidth, int screenHeight, std::string path, SDL_Renderer* wRenderer);
	~WallPaper();
	void draw();
	void setImage(std::string path);
	void update(int screenWidth, int screenHeight);
};

