#pragma once

#include "Text.h"

class EditText
{
private:
	bool isFocused;
	Text* mTextObj;
	std::string textInput;
	int xPos, yPos, width, height;
	int maxChar;
public:
	EditText();
	~EditText();
	void input(SDL_Event* eventListener);
	std::string getText();
};