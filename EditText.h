#pragma once

#include "Text.h"

class EditText
{
private:
	bool isFocused;
	Text* mTextObj;
	std::string textInput;
	int maxChar;
public:
	EditText(SDL_Renderer* pRenderer, int x, int y, int maxLength);
	~EditText();
	void input(SDL_Event* eventListener);
	std::string getText();
	void draw();
};