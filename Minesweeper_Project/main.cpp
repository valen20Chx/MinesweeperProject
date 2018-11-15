#include <iostream>
#include <SDL2/SDL.h>

#include "Display.h"
#include "Sprite.h"

int main(int argc, char** argv)
{
	Display mDisplay("Ma Fenetre", 500, 300, false);
	Sprite image1("Ressources/astro.bmp");
	while (!mDisplay.get_closeWindow())
	{
		mDisplay.eventHandler();
	}

	return 0;
}