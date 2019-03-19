#pragma once

#include <iostream>
#include <string>
#include <SDL.h>
#include "MainMenu.h"
#include "StateInGame.h"
#include "SettingGame.h"
#include "ScoreBoardScene.h"


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
	/*void(*quitFunc)(void);
	void(*switchToMainMenuFunc)(void);
	void(*switchToGameSettingsFunc)(void);
	void(*switchToScoreBoardFunc)(void);
	void(*switchToInGameFunc)(void);*/
public:
	Game(std::string title, int width, int height, bool fullScreen);
	~Game();
	void loop();
	void update();
	void input();
	void render();
	/////////////////////////////////////////////
	void switchToMainMenu(void);
	void switchToGameSettings(void) {}; //TODO
	void switchToInGame(void);
	void switchToScoreBoard(void) {}; //TODO
	void quitGame(void);
};