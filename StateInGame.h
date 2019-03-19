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
	StateInGame(SDL_Renderer * pRenderer, int x, int y, int width, int height, MinefieldSettings mineFieldSettings);
	~StateInGame();
	void draw();
	void windowSizeChanged(int width, int height);
	void input(Uint32 eventType);
	void set_gameResult();
};