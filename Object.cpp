#include "Object.h"

Object::Object()
{}

Object::~Object()
{}

SDL_Rect Object::get_dest() const
{
	return this->dest;
}

SDL_Rect Object::get_src() const
{
	return this->src;
}

SDL_Texture* Object::get_texture()
{
	return this->texture;
}

void Object::set_dest(int x, int y, int w, int h)
{
	this->dest.x = x;

	this->dest.y = y;

	this->dest.w = w;

	this->dest.h = h;
}

void Object::set_src(int x, int y, int w, int h)
{
	this->src.x = x;

	this->src.y = y;

	this->src.w = w;

	this->src.h = h;
}

void Object::setImage(std::string path, SDL_Renderer* renderer)
{
	
}