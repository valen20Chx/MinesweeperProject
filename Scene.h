#pragma once

#include "String.h"
#include "MineField.h"
#include "WallPaper.h"
#include "Text.h"
#include "ButtonText.h"


enum scene_action {
	ACTION_NONE,
	ACTION_QUITTER,
	ACTION_TO_INGAME,
	ACTION_TO_SETTINGS_GAME,
	ACTION_TO_MENU,
	ACTION_TO_SCOREBOARD,
	ACTION_SET_HARD,
	ACTION_SET_AVG,
	ACTION_SET_EASY,
	ACTION_SET_LARGE,
	ACTION_SET_MED,
	ACTION_SET_SMALL
};


const int P_BOMB_EASY = 10;
const int P_BOMB_AVG = 15;
const int P_BOMB_HARD = 20;
const int SIZE_SMALL = 7;
const int SIZE_MED = 10;
const int SIZE_LARGE = 14;

class Scene
{
protected:
	SDL_Renderer* mRenderer;
	int x, y, width, height;
	int action;
	MinefieldSettings mMineSettings;
	GameResult game_Result;

public:
	Scene(SDL_Renderer* mRenderer, int x, int y, int width, int height);
	~Scene();
	virtual void windowSizeChanged(int width, int height) {};
	virtual void draw() {};
	virtual void input(Uint32 eventType) {};
	int get_action();
	void set_action(int action);

	/// UNIQUE a SettingGame ///
	MinefieldSettings get_mineSettings();
	void set_easy();
	void set_average();
	void set_hard();
	void set_small();
	void set_medium();
	void set_large();
	void set_seed();
	///		///		///
	GameResult get_gameResult();
};