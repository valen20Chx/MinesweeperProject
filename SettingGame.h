#pragma once

#include "Scene.h"
class SettingGame : public Scene
{
private:
	Text* mDifficutyTxt;
	Text* mSizeTxt;

	SDL_Rect* m_srcBar;
	SDL_Rect* mBarSelectDiff;
	SDL_Rect* mBarSelectSize;
	SDL_Color mBarColor;
	SDL_Texture* textureBar;

	ButtonText* mBtnTxtEasy;
	ButtonText* mBtnTxtAverage;
	ButtonText* mBtnTxtHard;

	ButtonText* mBtnTxtSmall;
	ButtonText* mBtnTxtMedium;
	ButtonText* mBtnTxtLarge;

	ButtonText* mBtnTxtPlay;
	MinefieldSettings mMineSettings;

public:
	SettingGame(SDL_Renderer * pRenderer, int x, int y, int width, int height, MinefieldSettings* mineSettings);
	~SettingGame();
	void input(Uint32 eventType);
	void set_paramRect(SDL_Rect* rect, int x, int y, int w, int h);
	void draw();
};



