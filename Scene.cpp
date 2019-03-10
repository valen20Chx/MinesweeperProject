#include "Scene.h"



Scene::Scene(SDL_Renderer* pRenderer, int x, int y, int width, int height)
{
	this->mRenderer = pRenderer;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}


Scene::~Scene()
{
}
