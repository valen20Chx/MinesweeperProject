#include <iostream>
#include <SDL.h>

#include "Display.h"
#include "Sprite.h"

int main(int argc, char** argv)
{
	Display mDisplay("Ma Fenetre", 1280, 720, false);
	Sprite image1("Ressources\\astro.bmp");

	image1.apply(mDisplay.get_screenSurface());

	while (!mDisplay.get_closeWindow())
	{
		mDisplay.eventHandler();
		mDisplay.update();
	}

	return 0;
}