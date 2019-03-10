#pragma once

#include "Button.h"
#include "Text.h"
class ButtonText : public Button
{
private:
	Text* mText;
public:
	~ButtonText();
	ButtonText(SDL_Rect src, SDL_Rect dest, SDL_Renderer* pRenderer, int x, int y, short font_size, SDL_Color color, std::string fontPath, std::string  message);
	void draw();
	void updateBtnTxt(int diffWinW, int diffWinH);
};

