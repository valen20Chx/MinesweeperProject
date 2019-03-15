#include "Scene.h"

Scene::Scene(SDL_Renderer* pRenderer, int x, int y, int width, int height)
{
	this->mRenderer = pRenderer;
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->action = ACTION_NONE;
}

Scene::~Scene() {};

int Scene::get_action()
{
	return this->action;
}

void Scene::set_action(int action)
{
	this->action = action;
}