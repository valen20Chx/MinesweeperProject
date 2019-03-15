#pragma once

#include "Object.h"
#include "MineField.h"
#include "WallPaper.h"
#include "Text.h"
#include "ButtonText.h"

enum scene_action {
	ACTION_NONE,
	ACTION_QUITTER,
	ACTION_TO_INGAME,
	ACTION_TO_SETTINGS_GAME,
	ACTION_TO_MENU,
	ACTION_TO_SCOREBOARD,
	ACTION_SET_HARD,
	ACTION_SET_AVG,
	ACTION_SET_EASY,
	ACTION_SET_LARGE,
	ACTION_SET_MED,
	ACTION_SET_SMALL
};

class Scene
{
protected:
	SDL_Renderer* mRenderer;
	int x, y, width, height;
	int action;
public:
	Scene(SDL_Renderer* mRenderer, int x, int y, int width, int height);
	~Scene();
	virtual void windowSizeChanged(int width, int height) {};
	virtual void draw() {};
	virtual void input(Uint32 eventType) {};
	int get_action();
	void set_action();
};