#pragma once

#include "Text.h"
#include "String.h"

class EditText
{
private:
	bool isFocused;
	Text* mTextObj;
	std::string textInput;
	unsigned int maxChar;
	SDL_Rect inputRect;
	SDL_Renderer* mRenderer;
public:
	EditText(SDL_Renderer* pRenderer, int x, int y, unsigned int maxLength);
	~EditText();
	void input(SDL_Event eventListener);
	std::string getText();
	void draw();
};