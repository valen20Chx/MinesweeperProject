#include <iostream>
#include <SDL.h>
#include <string>

#include "Game.h"

int main(int argc, char** argv)
{
	Game mGame("Test1", 500, 500, false);
	mGame.drawMinefield();

	return 0;
}