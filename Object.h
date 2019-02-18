#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

class Object
{
protected:
	SDL_Rect dest;
	SDL_Rect src;
	SDL_Texture* texture;
public:
	Object();
	~Object();
	SDL_Rect get_dest() const;
	SDL_Rect get_src() const;
	SDL_Texture* get_texture();
	void set_dest(int x, int y, int w, int h);
	void set_src(int x, int y, int w, int h);
	void setImage(std::string path, SDL_Renderer* renderer);
};