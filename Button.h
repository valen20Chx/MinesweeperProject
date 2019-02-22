#pragma once

#include"Object.h"
class Button : public Object
{
private:
	std::string btnNom;
	int mouseX, mouseY;
	std::string pathPressed, pathPassif;
	SDL_Texture* texturePressed;

public:
	Button();
	~Button();
	Button(std::string btnNom, int srcX, int srcY, int srcW, int srcH, int destX, int destY, int destW, int destH);
	void setImagePressed(std::string pathPressed, SDL_Renderer* renderer);
	void estCliquer(int mouseX, int mouseY, SDL_Renderer* renderer);
	void setClicPos();
};

