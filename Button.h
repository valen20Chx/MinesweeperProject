#pragma once

#include"Object.h"
class Button : public Object
{
protected:
	std::string pathPressed, pathPassif;
	SDL_Texture* texturePressed;
	bool action = false;
	bool isSquare = false;
	SDL_Renderer* mRenderer;
public:
	Button();
	~Button();
	Button(SDL_Rect src, SDL_Rect dest,bool isSquare, SDL_Renderer* pRenderer);
	
	void setPath(std::string pathPassif, std::string pathPressed);
	virtual void updateBtn(int WinW, int WinH);
	void btnClic_down(int mouseX, int mouseY);
	void btnClic_up(int mouseX, int mouseY);
	void draw();
	bool get_action();
	void set_action(bool faux);
};

