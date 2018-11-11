#pragma once

#include <vector>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#include "Square.h"

#define PLAY_DIG 0
#define PLAY_FLAG 1

class MineField
{
private:
	int width, height;
	int percentBomb;
	std::vector<std::vector<Square>> grid;
	int nbBombs;
	int nbBombDiscovered;
public:
	MineField(int width, int height, int percentBomb);
	~MineField();
	int get_width();
	int get_height();
	int get_percentBomb();
	std::vector<std::vector<Square>> get_grid();
	Square get_square(int x, int y);
	void draw_gridASCII();
	void printStats();
	void play(int playType, int x, int y);
};

