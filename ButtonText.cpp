#include "ButtonText.h"

ButtonText::ButtonText(SDL_Rect* src, SDL_Rect* dest, SDL_Renderer* pRenderer,
	std::string pathRest, std::string pathPressed, short font_size, SDL_Color color, std::string fontPath, std::string  message)
	: Button(src, dest, pathRest, pathPressed, pRenderer)
{
	this->mText = new Text(pRenderer, this->dest->x, this->dest->y, font_size, color, fontPath, message);
}

void ButtonText::draw()
{
	this->Button::draw();
	mText->draw();
}

ButtonText::~ButtonText()
{
}
