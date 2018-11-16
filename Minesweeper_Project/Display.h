#pragma once

#include <SDL.h>
#include <iostream>
#include <string>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

class Display
{
private:
	int width, height;
	int Xpos, Ypos;
	bool isFullscreen;
	SDL_Window* window;
	SDL_Surface* screenSurface;
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
	int get_Xpos();
	int get_Ypos();
	bool get_closeWindow();
	void update();
	void eventHandler();
protected:
};