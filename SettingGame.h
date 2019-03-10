#pragma once

#include "Scene.h"
class SettingGame
{
private:
	Text* mDifficutyTxt;
	Text* mSizeTxt;

	Object* mBarSelect;

	ButtonText* mBtnTxtEasy;
	ButtonText* mBtnTxtAverage*;
	ButtonText* mBtnTxtHard;

	ButtonText* mBtnTxtSmall;
	ButtonText* mBtnTxtMedium;
	ButtonText* mBtnTxtLarge;

	ButtonText* mBtnTxtPlay;
public:
	SettingGame();
	~SettingGame();
	void onClicEasy();
	void onClicAverage();
	void onClicHard();
	void onClicSmall();
	void onClicMedium();
	void onClicLarge();

};

