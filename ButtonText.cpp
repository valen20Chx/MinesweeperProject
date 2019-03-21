#include "ButtonText.h"

ButtonText::ButtonText(SDL_Rect* src, SDL_Rect* dest, SDL_Renderer* pRenderer,
	std::string pathRest, std::string pathPressed, short font_size, SDL_Color color, std::string fontPath, std::string  message)
	: Button(src, dest, pathRest, pathPressed, pRenderer)
{
	this->mText = new Text(pRenderer, this->dest->x + 15, this->dest->y + 10, font_size, color, fontPath, message);
	this->dest->w = this->mText->get_rect_dest().w + 30;
	this->dest->h = this->mText->get_rect_dest().h + 20;
}

void ButtonText::draw()
{
	this->Button::draw();
	mText->draw();
}

void ButtonText::changePos(int x, int y)
{
	this->dest->x = x;
	this->dest->y = y;
	this->mText->set_rect_dest(this->dest->x + 15, this->dest->y + 10);
}

ButtonText::~ButtonText()
{
}
