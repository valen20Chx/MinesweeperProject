#include "EditText.h"

EditText::EditText()
{
}

EditText::~EditText()
{
}

void EditText::input(SDL_Event* eventListener)
{
	if (eventListener->type == SDL_TEXTINPUT)
	{
		this->textInput += eventListener->text.text;
	}
	if (eventListener->type == SDL_MOUSEBUTTONDOWN)
	{
		int x, y;
		if (eventListener->button.button == SDL_BUTTON_LEFT)
		{
			SDL_GetMouseState(&x, &y);

			if (x > this->xPos && x <(this->xPos + this->width + 1) && y > this->yPos && y < (this->yPos + this->height + 1))
			{
				if (!this->isFocused)
				{
					SDL_StartTextInput();
					this->isFocused = true;
				}
				std::cout << "le clic est sur le EditText" << std::endl;
			}
			else
			{
				if (this->isFocused)
				{
					SDL_StopTextInput();
					this->isFocused = false;
				}
				std::cout << "le clic est hors le EditText" << std::endl;
			}
		}
	}
}

std::string EditText::getText()
{
	return this->textInput;
}