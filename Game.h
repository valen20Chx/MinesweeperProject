#pragma once

#include <iostream>
#include <string>
#include <SDL.h>

#include "Object.h"
#include "MineField.h"
#include "WallPaper.h"
#include "Text.h"

enum game_state
{
	GAME_STATE_MAIN_MENU,
	GAME_STATE_IN_GAME,
	GAME_STATE_SETTINGS,
	GAME_STATE_GAME_OVER
};

class Game
{
private:
	int height, width;
	bool fullScreen, isRunning;
	std::string title;
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	int count, frameCount, timerFPS, lastFrame;
	Object star;
	int gameState;
	MineField* gameGrid;
	int mouseXpos, mouseYpos;
	WallPaper* mWallPaper;
	Text* monText;
public:
	Game(std::string title, int width, int height, bool fullScreen);
	~Game();
	void loop();
	void update();
	void input();
	void render();
	void drawMinefield();
	void draw(Object obj);
	void draMenu() {};
};