#include "ButtonText.h"

ButtonText::ButtonText(SDL_Rect src, SDL_Rect dest, SDL_Renderer* pRenderer, int x, int y, void(*func)(), std::string pathRest, std::string pathPressed, short font_size, SDL_Color color, std::string fontPath, std::string  message)
	:Button({ src.x, src.y, src.w, src.h }, { dest.x, dest.y, dest.w, dest.h }, false, func, pathRest, pathPressed, pRenderer)
{
	//a voir si il faut tout mettre dans ce constructeur
	this->isSquare = false;
	this->mText = new Text(pRenderer, x, y, font_size, color, fontPath, message);
	//this->mText->update(message);
}

void ButtonText::updateBtnTxtPos(int WinW, int WinH) //Redimentionne le Texte en fonction du boutton
{
	this->updateBtnPos(WinW, WinH);

	mText->set_rect_dest(dest.x + (dest.w / 8), dest.y + (dest.h / 6)); 
}

void ButtonText::draw()
{
	SDL_RenderCopy(this->mRenderer, this->texture, &this->src, &this->dest);
	mText->draw();
}

ButtonText::~ButtonText()
{
}
