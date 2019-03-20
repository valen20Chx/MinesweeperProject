#include "Button.h"


Button::Button(SDL_Rect* src, SDL_Rect* dest, std::string imageRestPath, std::string imagePressPath, SDL_Renderer* renderer)
{
	this->src = new SDL_Rect();
	this->dest = new SDL_Rect();
	this->src = src;
	this->dest = dest;
	this->imageRestPath = imageRestPath;
	this->imagePressPath = imagePressPath;
	this->mRenderer = renderer;

	this->isPressed = false;

	SDL_Surface* tempSurfaceRest = IMG_Load(this->imageRestPath.c_str());
	if (!tempSurfaceRest)
	{
		std::cerr << "ERROR : Could not load image : " << IMG_GetError() << std::endl;
	}

	this->restTexture = SDL_CreateTextureFromSurface(this->mRenderer, tempSurfaceRest);
	if (!this->restTexture)
	{
		std::cerr << "ERROR : Could not create restTexture" << SDL_GetError() << std::endl;
	}
	else
	{
		//SDL_QueryTexture(this->restTexture, NULL, NULL, &this->dest->w, &this->dest->h);
	}

	SDL_Surface* tempSurfacePressed = IMG_Load(this->imagePressPath.c_str());
	if (!tempSurfacePressed)
	{
		std::cerr << "ERROR : Could not load image : " << IMG_GetError() << std::endl;
	}

	this->pressedTexture = SDL_CreateTextureFromSurface(this->mRenderer, tempSurfacePressed);
	if (!this->pressedTexture)
	{
		std::cerr << "ERROR : Could not create pressedTexture" << SDL_GetError() << std::endl;
	}
	else
	{
		//SDL_QueryTexture(this->pressedTexture, NULL, NULL, &this->dest->w, &this->dest->h);
	}

	std::cout << "New Button : (" << this->dest->x << ", " << this->dest->y << ", " << this->dest->w << ", " << this->dest->h << ")" << std::endl;

	SDL_FreeSurface(tempSurfaceRest);
	SDL_FreeSurface(tempSurfacePressed);
}


Button::~Button()
{
	SDL_DestroyTexture(this->restTexture);
	SDL_DestroyTexture(this->pressedTexture);
}

void Button::draw()
{
	if (this->isPressed)
	{
		SDL_RenderCopy(this->mRenderer, this->pressedTexture, this->src, this->dest);
	}
	else
	{
		SDL_RenderCopy(this->mRenderer, this->restTexture, this->src, this->dest);
	}
}

bool Button::get_action()
{
	return this->launchAction;
}

void Button::set_action(bool action)
{
	this->launchAction = action;
}

void Button::input(SDL_Event eventListener)
{
	if (eventListener.type == SDL_MOUSEBUTTONDOWN && SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		//std::cout << " DOWN x : " << x << " | y : " << y << std::endl;
		//std::cout << " BTN  x : " << this->dest->x << " | y : " << this->dest->y << " | w : " << this->dest->w << " | h : " << this->dest->h << std::endl;
		if (x > this->dest->x && x < (this->dest->w + this->dest->x) && y > this->dest->y && y < (this->dest->h + this->dest->y))
		{
			std::cout << "pressed" << std::endl;
			this->isPressed = true;
		}
	}
	if (eventListener.type == SDL_MOUSEBUTTONUP && SDL_BUTTON(SDL_BUTTON_LEFT))
	{
		int x, y;
		SDL_GetMouseState(&x, &y);
		//std::cout << " UP   x : " << x << " | y : " << y << std::endl;
		//std::cout << " BTN  x : " << this->dest->x << " | y : " << this->dest->y << " | w : " << this->dest->w << " | h : " << this->dest->h << std::endl;
		if (x > this->dest->x && x < (this->dest->w + this->dest->x) && y > this->dest->y && y < (this->dest->h + this->dest->y))
		{
			if (this->isPressed)
			{
				this->launchAction = true;
			}
			this->isPressed = false;
		}
	}
}

void Button::changeRect(int x, int y, int w, int h)
{
	this->dest->x = x;
	this->dest->y = y;
	this->dest->w = w;
	this->dest->h = h;
}

void Button::changePos(int x, int y)
{
	this->dest->x = x;
	this->dest->y = y;
}

void Button::changeSize(int w, int h)
{
	this->dest->w = w;
	this->dest->h = h;
}

void Button::changeX(int x)
{
	this->dest->x = x;
}

void Button::changeY(int y)
{
	this->dest->y = y;
}

void Button::changeWidth(int w)
{
	this->dest->w = w;
}

void Button::changeHeight(int h)
{
	this->dest->h = h;
}

SDL_Rect Button::get_dest()
{
	return *this->dest;
}
