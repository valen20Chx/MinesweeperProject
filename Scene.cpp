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

MinefieldSettings Scene::get_mineSettings()
{
	return this->mMineSettings;
}


void Scene::set_easy()
{
	this->mMineSettings.percentBomb = P_BOMB_EASY;
}
void Scene::set_average()
{
	this->mMineSettings.percentBomb = P_BOMB_AVG;
}
void Scene::set_hard()
{
	this->mMineSettings.percentBomb = P_BOMB_HARD;
}
void Scene::set_small()
{
	this->mMineSettings.width = SIZE_SMALL;
	this->mMineSettings.height = SIZE_SMALL;
}
void Scene::set_medium()
{
	this->mMineSettings.width = SIZE_MED;
	this->mMineSettings.height = SIZE_MED;
}
void Scene::set_large()
{
	this->mMineSettings.width = SIZE_LARGE;
	this->mMineSettings.height = SIZE_LARGE;
}

void Scene::set_seed()
{
	this->mMineSettings.seed = (int)(rand() / (double)RAND_MAX * (157 - 1));
}


GameResult Scene::get_gameResult()
{
	return this->game_Result;
}

