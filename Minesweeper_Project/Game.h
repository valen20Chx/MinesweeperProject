#pragma once

#include <iostream>
#include <string>
#include <SDL.h>

#include "Object.h"

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
public:
	Game(std::string title, int width, int height, bool fullScreen);
	~Game();
	void loop();
	void update();
	void input();
	void render();
	void draw(Object obj);
};

