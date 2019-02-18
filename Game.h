#pragma once

#include <iostream>
#include <string>
#include <SDL.h>

#include "Object.h"
#include "MineField.h"

enum game_state
{
	GAME_STATE_MAIN_MENU,
	GAME_STATE_IN_GAME,
	GAME_STATE_SETTINGS,
	GAME_STATE_GAME_OVER
}; //je sais pas trop pourquoi

class Game
{
private:
	int height, width;
	bool fullScreen, isRunning; //non plus trop, a voir
	std::string title;
	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	int count, frameCount, timerFPS, lastFrame;
	Object star;
	int gameState; 
	MineField* gameGrid;
public:
	Game(std::string title, int width, int height, bool fullScreen);
	~Game();
	void loop(); 
	void update(); 
	void input();
	void render(); // efface ce qui a sur l'ecran
	void drawMinefield();
	void draw(Object obj); 
	void draMenu() {};
};

