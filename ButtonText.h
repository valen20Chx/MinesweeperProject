#pragma once

#include "Button.h"
#include "Text.h"
class ButtonText : public Button, Text
{
public:
	ButtonText();
	~ButtonText();
	ButtonText(std::string btnNom, int srcX, int srcY, int srcW, int srcH, int destX, int destY, int destW, int destH,
		SDL_Renderer* pRenderer, int txtX, int txtY, short font_size, SDL_Color color, std::string fontPath, std::string  message);
	void drawBtnTxt();
	void update();
};

