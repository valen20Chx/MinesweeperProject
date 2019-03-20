#include "EditText.h"

EditText::EditText(SDL_Renderer* pRenderer, int x, int y, unsigned int maxLength)
{
	this->maxChar = maxLength;
	this->inputRect.x = x;
	this->inputRect.y = y;
	this->mRenderer = pRenderer;
	this->mTextObj = new Text(this->mRenderer, this->inputRect.x + 5, this->inputRect.y + 5, 24, BLACK, FONT_BOLD, "");
	this->inputRect.w = (this->maxChar * 5) + 10;
	this->inputRect.h = this->mTextObj->get_rect_dest().h + 10;
	this->isFocused = false;
	this->textInput = "";
}

EditText::~EditText()
{
}

void EditText::input(SDL_Event eventListener)
{
	if (eventListener.type == SDL_TEXTINPUT)
	{
		if (eventListener.type == SDL_KEYDOWN && SDL_GetKeyboardState(NULL)[SDL_SCANCODE_BACKSPACE] && this->textInput.length() > 0)
		{
			this->textInput = this->textInput.substr(0, this->textInput.length() - 1);
		}
		else if (eventListener.type == SDL_TEXTINPUT)
		{
			if (this->textInput.length() < this->maxChar)
			{
				this->textInput += eventListener.text.text;
			}
		}
		this->mTextObj->update(this->textInput);
		this->textInput += eventListener.text.text;
	}
	if (eventListener.type == SDL_MOUSEBUTTONDOWN)
	{
		int x, y;
		if (eventListener.button.button == SDL_BUTTON_LEFT)
		{
			SDL_GetMouseState(&x, &y);

			if (x > this->inputRect.x && x <(this->inputRect.x + this->inputRect.w + 1) && y > this->inputRect.y && y < (this->inputRect.y + this->inputRect.h + 1))
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