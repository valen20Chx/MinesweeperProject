#include "Renderer.h"

Renderer::Renderer(SDL_Window* mWindow)
{
	this->mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (this->mRenderer == nullptr)
	{
		std::cerr << "Renderer creation error : " << std::endl;
		std::cerr << SDL_GetError() << std::endl;
	}
}


Renderer::~Renderer()
{
	SDL_DestroyRenderer(this->mRenderer);
}

SDL_Renderer* Renderer::get_mRenderer()
{
	return this->mRenderer;
}