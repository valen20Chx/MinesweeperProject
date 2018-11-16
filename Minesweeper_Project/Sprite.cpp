#include "Sprite.h"

Sprite::Sprite(std::string path)
{
	this->path = path;
	this->isLoaded = true;

	this->gSpriteSurface = SDL_LoadBMP(this->path.c_str());

	if (this->gSpriteSurface == NULL)
	{
		std::cerr << "Error : Cant load Image" << this->path << std::endl;
		std::cerr << SDL_GetError() << std::endl;
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

	if (SDL_BlitSurface(this->gSpriteSurface, NULL, gScreenSurface, NULL))
	{
		std::cerr << "Blitz surface Error : " << SDL_GetError() << std::endl;
	}
}

SDL_Surface* Sprite::get_Surface()
{
	return this->gSpriteSurface;
}