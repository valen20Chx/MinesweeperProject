#pragma once

#include "Scene.h"
#include "ButtonText.h"
#include "WallPaper.h"

typedef struct {
	bool success;
	unsigned int temps;
	unsigned int nbBombes;
}Game_Result;

class ScoreBoardScene : public Scene
{
private:
	WallPaper* mWallPaper;
	Button* btnQuit;
	Button* btnHome;
	std::vector<Text*> txtListStats;
	Game_Result game_Result;
	int time;
	int nbBombes;
public:
	ScoreBoardScene(SDL_Renderer* pRenderer, int x, int y, int width, int height, void(*quitFunc)(), void(*homeFunc)(), Game_Result game_Result);
	~ScoreBoardScene();
	void draw() {};
	void input(SDL_Event* eventListener);
	void updateWindowSize(int width, int height);
};

