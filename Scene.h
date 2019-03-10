#pragma once

#include "Object.h"
#include "MineField.h"
#include "WallPaper.h"
#include "Text.h"
#include "ButtonText.h"

class Scene
{
protected:
	SDL_Renderer* mRenderer;
	int x, y, width, height;
public:
	Scene(SDL_Renderer* mRenderer, int x, int y, int width, int height);
	~Scene();
	void windowSizeChanged(int width, int height);
	virtual void draw() {};
};