#include "Sprite.h"

Sprite::Sprite(std::string path)
{
	this->gSpriteSurface = SDL_LoadBMP(this->path.c_str());

	this->isLoaded = true;

	if (this->gSpriteSurface == NULL)
	{
		std::cerr << "Error : Cant load Image" << this->path << std::endl;
		this->isLoaded = false;
	}
}

Sprite::~Sprite()
{
	SDL_FreeSurface(this->gSpriteSurface);
}

bool Sprite::get_isLoaded()
{
	return this->isLoaded;
}

void Sprite::apply(SDL_Surface* gScreenSurface)
{
	this->gScreenSurface = gScreenSurface;

	SDL_BlitSurface(gSpriteSurface, NULL, gScreenSurface, NULL);
}
