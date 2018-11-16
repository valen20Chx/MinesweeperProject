#pragma once

#include <SDL.h>
#include <iostream>

class Texture
{
private:
	SDL_Texture* mTexture;
public:
	Texture(SDL_Surface* image, SDL_Renderer* mRenderer);
	~Texture();
	SDL_Texture* get_mTexture();
};

