#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include "MainMenu.h"
#include "StateInGame.h"
#include "SettingGame.h"
#include "ScoreBoardScene.h"
#include "SceneConnect.h"
#include "Reseau.h"

enum game_state
{
	GAME_STATE_MAIN_MENU,
	GAME_STATE_IN_GAME,
	GAME_STATE_SETTINGS,
	GAME_STATE_SCOREBOARD
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
	int gameState;
	Scene* gameScene;
	Reseau* mReseau;
public:
	Game(std::string title, int width, int height, bool fullScreen);
	~Game();
	void loop();
	void update();
	void input();
	void render();
};