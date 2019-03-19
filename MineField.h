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
#define GAME_MARGIN_TOP 60
#define GAME_MARGIN_BOTTOM 10
#define GAME_MARGIN_RIGHT 20

#define MF_STATE_NONE 0
#define MF_STATE_STARTED 1
#define MF_STATE_WON 2
#define MF_STATE_LOSS 3

typedef struct
{
	int nbBomb;
	int nbGoodFlag;
	unsigned int time;
	bool won;
}GameResult;

typedef struct {
	int width;
	int height;
	int percentBomb;
	int seed;
} MinefieldSettings;

class MineField
{
private:
	int width, height;
	int percentBomb;
	std::vector<std::vector<Square>> grid;
	int nbBombs;
	int nbGoodFlag;
	unsigned int seed;
	int state;
	int nbFlags;
	std::vector<SDL_Point> bombsPos;
	unsigned int startTime;
	unsigned int endTime;
	SDL_Renderer* mRenderer;
public:
	MineField(int width, int height, int percentBomb, unsigned int seed);
	MineField(MinefieldSettings minefieldSettings);
	~MineField();
	void set_nbGoodFlag();
	int get_nbGoodFlag();
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
	unsigned int getRuningTicks();
	void input(Uint32 eventType, int width, int height);
	void set_percentBomb(int prctBomb);
	void set_size(int width, int height);
	int get_nbBomb();
	bool get_isWon();
	bool get_isFinished();
};