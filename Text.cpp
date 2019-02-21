#include "Text.h"

Text::Text(SDL_Renderer* pRenderer, int x, int y, short font_size, SDL_Color color, std::string fontPath, std::string  message)
{
	this->mRenderer = pRenderer;
	this->text = message;

	this->mFont = TTF_OpenFont(fontPath.c_str(), font_size);
	if (!this->mFont) std::cout << "Font Error" << std::endl;

	this->color = color;

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(this->mFont, this->text.c_str(), this->color);
	if (!surfaceMessage) std::cout << "Surface Error" << std::endl;
	else
	{
		this->rect_dest.x = x;
		this->rect_dest.y = y;

		this->mTexture = SDL_CreateTextureFromSurface(this->mRenderer, surfaceMessage);
		SDL_QueryTexture(this->mTexture, NULL, NULL, &this->rect_dest.w, &this->rect_dest.h);
	}

	SDL_FreeSurface(surfaceMessage);
}

Text::~Text()
{
	SDL_DestroyTexture(this->mTexture);
	TTF_CloseFont(this->mFont);
}

void Text::update(std::string message)
{
	SDL_Surface *tSurface;

	tSurface = TTF_RenderText_Solid(this->mFont, message.c_str(), this->color);
	if (tSurface == NULL) std::cout << "Surface Error" << std::endl;
	else
	{
		SDL_QueryTexture(this->mTexture, NULL, NULL, &this->rect_dest.w, &this->rect_dest.h);
	}

	this->mTexture = SDL_CreateTextureFromSurface(this->mRenderer, tSurface);

	SDL_QueryTexture(this->mTexture, NULL, NULL, &this->rect_dest.w, &this->rect_dest.h);

	SDL_FreeSurface(tSurface);
}

void Text::draw()
{
	SDL_RenderCopy(this->mRenderer, this->mTexture, NULL, &this->rect_dest);
}