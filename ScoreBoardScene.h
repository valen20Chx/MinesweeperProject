#pragma once

#include "Scene.h"
#include "ButtonText.h"
#include "WallPaper.h"

class ScoreBoardScene : public Scene
{
private:
	WallPaper* mWallPaper;
	Button* btnQuit;
	Button* btnHome;
	std::vector<Text*> txtListStats;
public:
	ScoreBoardScene(SDL_Renderer* pRenderer, int x, int y, int width, int height, void(*quitFunc)(), void(*homeFunc)());
	~ScoreBoardScene();
	void draw() {};
	void input(SDL_Event* eventListener);
	void updateWindowSize(int width, int height);
};

