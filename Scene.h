#pragma once

#include "Object.h"
#include "MineField.h"
#include "WallPaper.h"
#include "Text.h"
#include "ButtonText.h"

#define WidthBTN_SQUARE = this->width/16;
#define HeightBTN_SQUARE = this->height/16;
#define WidthBTN_TXT = this->width/16;
#define HeightBTN_TXT = this->height/25;
class Scene
{
protected:
	SDL_Renderer* mRenderer;
	int x, y, width, height;
public:
	Scene(SDL_Renderer* mRenderer, int x, int y, int width, int height);
	~Scene();
};

