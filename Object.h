#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include <SDL_image.h>

class Object
{
protected:
	SDL_Rect dest; //"envoyer" la partie l'image entré en parametre sur l'ecran
	SDL_Rect src; ////"definir" la partie l'image entré en parametre à l'objet
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

