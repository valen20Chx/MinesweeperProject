#pragma once
#include "Object.h"
#include <string>
#include <iostream>
#include "SDL_ttf.h"

class Text
{
private:
	std::string text;
	std::string font_way;
	int x, y;
	short font_size;
	SDL_Renderer * mRenderer;
	Uint32 i_color;
	SDL_Texture *mTexture;
	TTF_Font *p_font;
	SDL_Rect     rect_dest;
	SDL_Color  color;
public:
	Text();
	~Text();
	Text(SDL_Renderer * p_renderer,int x, int y,short font_size, Uint32 i_color,std::string font_way, std::string  message);
	void update(std::string message);
	void draw();
};




