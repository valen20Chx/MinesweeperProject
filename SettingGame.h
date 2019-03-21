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

	WallPaper* mWallpaper;

	bool mSize_selected, mDiff_selected;

public:
	SettingGame(SDL_Renderer * pRenderer, int x, int y, int width, int height);
	~SettingGame();
	void input(SDL_Event eventListener);
	void draw();
	void set_mineSettings(MinefieldSettings mS);
	void set_buttonPos(int width, int height);
	void windowSizeChanged(int width, int height);
};



