#include "Button.h"


Button::Button(SDL_Rect src, SDL_Rect dest, bool isSquare, void(*func)(), std::string pathRest, std::string pathPressed, SDL_Renderer* pRenderer)
{
	this->btnRectDest = { dest.x, dest.y, dest.w, dest.h };
	this->btnRectSrc = { src.x,  src.y,  src.w,  src.h };
	this->isSquare = isSquare;
	this->mRenderer = pRenderer;
	this->isPressed = false;
	this->func = func;

	SDL_Surface* surface = IMG_Load(pathPressed.c_str());
	this->texturePressed = SDL_CreateTextureFromSurface(this->mRenderer, surface);

	surface = IMG_Load(pathRest.c_str());
	this->textureRest = SDL_CreateTextureFromSurface(this->mRenderer, surface);

	SDL_FreeSurface(surface);
}

void Button::input(SDL_Event* eventListener)
{
	if (eventListener->type == SDL_MOUSEBUTTONDOWN)
	{
		int x, y;
		if (eventListener->button.button == SDL_BUTTON_LEFT)
		{
			SDL_GetMouseState(&x, &y);

			if (x > this->dest.x && x <(this->dest.x + this->dest.w + 1) && y > this->dest.y && y < (this->dest.y + this->dest.h + 1))
			{
				this->isPressed = true;
				std::cout << "le clic est sur le boutton" << std::endl;
			}
		}
	}
	if (eventListener->type == SDL_MOUSEBUTTONUP)
	{
		int x, y;
		if (eventListener->button.button == SDL_BUTTON_LEFT)
		{
			SDL_GetMouseState(&x, &y);

			//si il relache le clic sur le boutton
			if (x > this->dest.x && x <(this->dest.x + this->dest.w + 1) && y > this->dest.y && y < (this->dest.y + this->dest.h + 1) && isPressed == true)
			{
				this->isPressed = false;
				std::cout << "Action du clic" << std::endl;
				this->action = true;
				// Appel la fonction pointee par le membre func
				if (this->func)
					func();
			}
			else if (isPressed == true)
			{
				puts("Le clic est relacher or du boutton");
				isPressed = false;
			}
		}
	}
}

void Button::draw()
{
	// afficher a la position x et y
	if (this->isPressed)
	{
		SDL_RenderCopy(this->mRenderer, this->texturePressed, &this->src, &this->dest);
	}
	else
	{
		SDL_RenderCopy(this->mRenderer, this->textureRest, &this->src, &this->dest);
	}
}

void Button::updateBtnPos(int winW, int winH) // Non-Sense
{
	//redimensionner le boutton en fonction de la fenettre
	if (this->isSquare == false)
	{
		this->dest.w = winW / 16;
		this->dest.h = winH / 25;
	}
	else
	{
		this->dest.w = winW / 16;
		this->dest.h = winH / 16;
	}
 }

Button::~Button()
{}

bool Button::get_action()
{
	return this->action;
}

void Button::set_action(bool action)
{
	this->action = action;
}