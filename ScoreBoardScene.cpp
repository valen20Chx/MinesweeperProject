#include "ScoreBoardScene.h"

ScoreBoardScene::ScoreBoardScene(SDL_Renderer* pRenderer, int x, int y, int width, int height,
	void(*quitFunc)(), void(*homeFunc)()) : Scene(pRenderer, x, y, width, height)
{

}

ScoreBoardScene::~ScoreBoardScene()
{
}

void ScoreBoardScene::input(SDL_Event* eventListener)
{
	this->btnHome->input(eventListener);
	this->btnQuit->input(eventListener);
}

void ScoreBoardScene::updateWindowSize(int width, int height)
{
	this->width = width;
	this->height = height;
}