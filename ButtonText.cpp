#include "ButtonText.h"

ButtonText::ButtonText(std::string btnNom, int srcX, int srcY, int srcW, int srcH, int destX, int destY, int destW, int destH,
	SDL_Renderer* pRenderer, int txtX, int txtY, short font_size, SDL_Color color, std::string fontPath, std::string  message)
{
	Button(btnNom, srcX, srcY, srcW, srcH, destX, destY, destW, destH);
	Text(pRenderer, txtX, txtY, font_size, color, fontPath, message);
	//a voir si il faut tout mettre dans ce constructeur
}

void ButtonText::update() //Redimentionne le Texte
{
	//Text.# = Button.#(centré)
	this->rect_dest.x = dest.x + (dest.w / 8); //positione a  1/8 eme du bord
	this->rect_dest.y = dest.y + (dest.h / 6); //positione a  1/6 eme du bord
	this->rect_dest.w = dest.w - (dest.w / 4); //fais un quart de moins que le boutton
	this->rect_dest.h = dest.h - (dest.h / 3); //fais un tier de moins que le boutton
}


void ButtonText::drawBtnTxt()
{
	//image
	SDL_RenderCopy(this->mRenderer, this->texture, &src, &dest);
	//Text
	this->draw();
	
}

ButtonText::ButtonText()
{
}


ButtonText::~ButtonText()
{
}
