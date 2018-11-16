#include "Texture.h"

Texture::Texture(SDL_Surface* image, SDL_Renderer* mRenderer)
{
	this->mTexture = SDL_CreateTextureFromSurface(mRenderer, image);

	if (this->mTexture == nullptr)
	{
		this->~Texture();
		std::cerr << "Texture Creation Error : " << std::endl;
		std::cerr << SDL_GetError() << std::endl;
	}
}

Texture::~Texture()
{
}

SDL_Texture* Texture::get_mTexture()
{
	return this->mTexture;
}