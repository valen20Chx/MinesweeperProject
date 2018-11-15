#pragma once

#include <SDL2/SDL.h>
#include <iostream>
#include <string>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class Display
{
private:
	int width, height;
	bool isFullscreen;
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	std::string title;
	SDL_Event mEvent;
	bool closeWindow;
public:
	Display(std::string title, int width, int height, bool isFullscreen);
	~Display();
	SDL_Window* get_window();
	SDL_Surface* get_screenSurface();
	std::string get_title();
	int get_width();
	int get_height();
	bool get_closeWindow();
	void update();
	void eventHandler();
protected:
};