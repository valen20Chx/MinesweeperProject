#include "EditText.h"

EditText::EditText(SDL_Renderer* pRenderer, int x, int y, unsigned int maxLength)
{
	this->mTextObj = new Text(pRenderer, x, y, 24, { 255, 255, 255, 255 }, "Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "");
	this->maxChar = maxLength;
}

EditText::~EditText()
{
}

void EditText::input(SDL_Event* eventListener)
{
	if (eventListener->type == SDL_TEXTINPUT || SDL_KEYDOWN)
	{
		if (eventListener->type == SDL_KEYDOWN && eventListener->key.keysym.sym == SDLK_BACKSPACE && this->textInput.length() > 0)
		{
			this->textInput = this->textInput.substr(0, this->textInput.length() - 1);
		}
		else if (eventListener->type == SDL_TEXTINPUT)
		{
			if (this->textInput.length() < this->maxChar)
			{
				this->textInput += eventListener->text.text;
			}
		}
		this->mTextObj->update(this->textInput);
	}
	if (eventListener->type == SDL_MOUSEBUTTONDOWN)
	{
		int x, y;
		if (eventListener->button.button == SDL_BUTTON_LEFT)
		{
			SDL_GetMouseState(&x, &y);

			if (x > this->mTextObj->getDestRect().x && x <(this->mTextObj->getDestRect().x + this->mTextObj->getDestRect().w + 1) && y > this->mTextObj->getDestRect().y && y < (this->mTextObj->getDestRect().y + this->mTextObj->getDestRect().h + 1))
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

void EditText::draw()
{
	this->mTextObj->draw();
}