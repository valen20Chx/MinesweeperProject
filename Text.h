#pragma once


#include <string>
#include <iostream>

#include "SDL_ttf.h"
#include "Object.h"


class Text
{
protected:
	std::string text;
	SDL_Renderer* mRenderer;
	SDL_Texture *mTexture;
	TTF_Font* mFont;
	SDL_Rect rect_dest;
	SDL_Color color;
	int font_size;
public:
	Text(SDL_Renderer* pRenderer, int x, int y, short font_size, SDL_Color color, std::string fontPath, std::string  message);
	~Text();
	void update(std::string message);
	void draw();
	void update_size(int diffWinW, int diffWinH);
	void set_rect_dest(int x, int y);
	SDL_Rect getDestRect();
};