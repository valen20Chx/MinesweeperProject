#pragma once

#include "Scene.h"

class StateInGame : public Scene
{
private:
	Text* nbFlag;
	Text* time;
	MineField* gameGrid;
	Button* btnFermer;
	ButtonText* btnTxtHome;
	ButtonText* btnTxtResart;
	Button* btnParam;
public:
	StateInGame(SDL_Renderer * pRenderer, int x, int y, int width, int height, void(*quitFunc)(), void(*mainMenuFunc)());
	~StateInGame();
	void draw();
	void updateWindowSize(int W, int H);
	void input(SDL_Event* eventHandler);
};