#pragma once

#include "Scene.h"

class MainMenu : public Scene
{
protected:
	WallPaper* mWallpaper;
	ButtonText* mBtnTxtSolo;
	ButtonText* mBtnTxtMulti;
	Button* mBtnFermer;
public:
	MainMenu(SDL_Renderer * pRenderer, int x, int y, int width, int height);
	void windowSizeChanged(int width, int height);
	~MainMenu();
	void draw();
	void input(SDL_Event eventListener);
	void goSolo() {};
	void goMulti() {};
	void quitter() {};
};