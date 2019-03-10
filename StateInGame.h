#pragma once

#include "Scene.h"
class StateInGame : public Scene
{
private:
	Text* nbFlag;
	Text* time;

public:
	MineField* gameGrid;
	Button* btnFermer;
	ButtonText * btnTxtHome;
	ButtonText* btnTxtResart;
	Button* btnParam;
	StateInGame(SDL_Renderer * pRenderer, int x, int y, int width, int height);
	~StateInGame();
	void draw();
	void Update(int diffWinW, int diffWinH);
};

