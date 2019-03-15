#pragma once

#include "Object.h"

class Button
{
protected:
	SDL_Rect* src, *dest;
	SDL_Texture* pressedTexture, *restTexture;
	std::string imageRestPath, imagePressPath;
	SDL_Renderer* mRenderer;
	bool isPressed;
	bool launchAction;
public:
	Button(SDL_Rect* src, SDL_Rect* dest, std::string imageRestPath, std::string imagePressPath, SDL_Renderer* renderer);
	~Button();
	void draw();
	bool get_action();
	void set_action(bool action);
	void input(Uint32 eventType);
	void changeRect(int x, int y, int w, int h);
	void changePos(int x, int y);
	void changeSize(int w, int h);
	void changeX(int x);
	void changeY(int y);
	void changeWidth(int w);
	void changeHeight(int h);
	SDL_Rect get_dest();
};

