#include "Display.h"

Display::Display(std::string title, int width, int height, bool isFullscreen)
{
	this->width = width;
	this->height = height;
	this->title = title;
	this->closeWindow = false;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Error : Could not init SDL" << std::endl;
	}
	else
	{
		this->window = SDL_CreateWindow(this->title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->width, this->height, SDL_WINDOW_SHOWN);
		if (this->window == NULL)
		{
			std::cerr << "Error : Window could not be created." << std::endl;
		}
		else
		{
			this->screenSurface = SDL_GetWindowSurface(this->window);

			SDL_FillRect(this->screenSurface, NULL, SDL_MapRGB(this->screenSurface->format, 0xFF, 0xFF, 0xFF));

			SDL_UpdateWindowSurface(this->window);
		}
	}
}

Display::~Display()
{
	SDL_DestroyWindow(window);

	SDL_Quit();
}

SDL_Window* Display::get_window()
{
	return this->window;
}

SDL_Surface* Display::get_screenSurface()
{
	return this->screenSurface;
}

std::string Display::get_title()
{
	return this->title;
}

int Display::get_width()
{
	return this->width;
}

int Display::get_height()
{
	return this->height;
}

void Display::update()
{
	SDL_UpdateWindowSurface(this->window);
}

void Display::eventHandler()
{
	while (!this->closeWindow)
	{
		while (SDL_PollEvent(&(this->mEvent)) != 0)
		{
			if (this->mEvent.type == SDL_QUIT)
			{
				this->closeWindow = true;
				this->~Display();
			}
		}
	}
}

bool Display::get_closeWindow()
{
	return this->closeWindow;
}

int Display::get_Xpos()
{
	return this->Xpos;
}

int Display::get_Ypos()
{
	return this->Ypos;
}