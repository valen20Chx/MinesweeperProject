#pragma once

#include"Object.h"

class Button : public Object
{
protected:
	SDL_Texture* texturePressed;
	SDL_Texture* textureRest;
	SDL_Rect btnRectDest;
	SDL_Rect btnRectSrc;
	bool action = false;
	bool isPressed;
	bool isSquare = false;
	SDL_Renderer* mRenderer;
	void(*func)();
public:
	~Button();
	Button(SDL_Rect src, SDL_Rect dest, bool isSquare, void(*func)(), std::string pathRest, std::string pathPressed, SDL_Renderer* pRenderer);
	virtual void updateBtnPos(int WinW, int WinH);
	void input(SDL_Event* eventListener);
	void draw();
	bool get_action();
	void set_action(bool action);
};

