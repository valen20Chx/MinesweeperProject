#pragma once

#include "Scene.h"
class SettingGame : public 
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
	SettingGame(this->mRenderer, 0, 0, this->width, this->height)
		~SettingGame();
	void onClicEasy();
	void onClicAverage();
	void onClicHard();
	void onClicSmall();
	void onClicMedium();
	void onClicLarge();
	

};

