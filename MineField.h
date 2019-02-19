#pragma once

#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <SDL.h>

#include "Square.h"

#define PLAY_DIG 0
#define PLAY_FLAG 1

#define GAME_MARGIN_LEFT 20
#define GAME_MARGIN_TOP 40
#define GAME_MARGIN_BOTTOM 20
#define GAME_MARGIN_RIGHT 20

#define MF_STATE_NONE 0
#define MF_STATE_STARTED 1
#define MF_STATE_WON 2
#define MF_STATE_LOSS 3


class MineField
{
private:
	int width, height;
	int percentBomb;
	std::vector<std::vector<Square>> grid;
	int nbBombs;
	int nbBombDiscovered;
	unsigned int seed;
	int state;
	int nbFlags;
	std::vector<SDL_Point> bombsPos;
public:
	MineField(int width, int height, int percentBomb, unsigned int seed);
	~MineField();
	int get_width();
	int get_height();
	int get_percentBomb();
	int get_nbFlags();
	void set_nbFlags(int nbFlags);
	std::vector<std::vector<Square>> get_grid();
	Square get_square(int x, int y);
	int get_state();
	void set_state(int state);
	void draw_gridASCII();
	void printStats();
	void play(int playType, int x, int y, int screenWidth, int screenHeight);
	void play_reveal(int x, int y);
	void set_Squares(int screenWidth, int screenHeight, SDL_Renderer* screenRenderer);
	void update_Squares(int screenWidth, int screenHeight);
	void draw(SDL_Renderer* renderer);
	void update();
};