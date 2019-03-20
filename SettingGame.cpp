#include "SettingGame.h"

SettingGame::SettingGame(SDL_Renderer * pRenderer, int x, int y, int width, int height) : Scene(pRenderer, x, y, width, height)
{
	//Charger les Text
	this->mDifficutyTxt = new Text(this->mRenderer,width/2 - 50, this->height / 5, 24, GOLD, FONT_BOLD, "DIFFICULTY");
	this->mSizeTxt = new Text(this->mRenderer, width/ 2 - 35, this->height / 20*11, 24, GOLD, FONT_BOLD, "SIZE");
		
	//Charger les coordonées des boutton
	int margeBtnDiff = (width - (this->mbtnTxtEasy->get_dest().w + this->mBtnTxtAverage->get_dest().w + this->mBtnTxtHard->get_dest().w)) / 3
	int margeBtnSize = (width - (this->mbtnTxtSmall->get_dest().w + this->mBtnTxtMedium->get_dest().w + this->mBtnTxtLarge->get_dest().w)) / 3


	SDL_Rect* btnEasyRect = new SDL_Rect();
	*btnEasyRect = { width / 5, this->mDifficutyTxt->get_rect_dest().y + 30, 70, 32 };
	SDL_Rect* btnAvgRect = new SDL_Rect();
	*btnAvgRect = { width / 20 * 9, this->mDifficutyTxt->get_rect_dest().y + 30, 70, 32 };
	SDL_Rect* btnHardRect = new SDL_Rect();
	*btnHardRect = { width / 10 * 7, this->mDifficutyTxt->get_rect_dest().y + 30, 70, 32 };

	SDL_Rect* btnSmallRect = new SDL_Rect();
	*btnSmallRect = { width / 5, this->mSizeTxt->get_rect_dest().y + 30, 70, 32 };
	SDL_Rect* btnMedRect = new SDL_Rect();
	*btnMedRect = { width / 20 * 9,this->mSizeTxt->get_rect_dest().y + 30, 70, 32 };
	SDL_Rect* btnLargeRect = new SDL_Rect();
	*btnLargeRect = { width / 10 * 7, this->mSizeTxt->get_rect_dest().y + 30, 70, 32 };
	
	//Charger les bouttons
	this->mBtnTxtEasy = new ButtonText(NULL, btnEasyRect, this->mRenderer,
		BUTTON_REST, BUTTON_PRESSED, 18, { 100,100,255, 255 },FONT_BOLD, "EASY");
	this->mBtnTxtAverage = new ButtonText(NULL, btnAvgRect, this->mRenderer,
		BUTTON_REST, BUTTON_PRESSED, 18, { 100,100,255, 255 },FONT_BOLD, "AVERAGE");	
	this->mBtnTxtHard = new ButtonText(NULL, btnHardRect, this->mRenderer,
		BUTTON_REST, BUTTON_PRESSED, 18, { 100,100,255, 255 },FONT_BOLD, "HARD");
	
	this->mBtnTxtSmall = new ButtonText(NULL, btnSmallRect, this->mRenderer,
		BUTTON_REST, BUTTON_PRESSED, 18, { 100,100,255, 255 },FONT_BOLD, "SMALL");
	this->mBtnTxtMedium = new ButtonText(NULL, btnMedRect, this->mRenderer,
		BUTTON_REST, BUTTON_PRESSED, 18, { 100,100,255, 255 }, FONT_BOLD, "MEDIUM");
	this->mBtnTxtLarge = new ButtonText(NULL, btnLargeRect, this->mRenderer,
		BUTTON_REST, BUTTON_PRESSED, 18, { 100,100,255, 255 },FONT_BOLD, "LARGE");


	SDL_Rect* btnPlayRect = new SDL_Rect();
	*btnPlayRect = { width / 3, height / 4*3, 90, 45 };
	this->mBtnTxtPlay = new ButtonText(NULL, btnPlayRect, this->mRenderer,
		BUTTON_REST, BUTTON_PRESSED, 25, { 100,100,255, 255 }, FONT_BOLD, "PLAY");

	
	//Charger les Bar de seletection
	this->mBarSelectDiff = new SDL_Rect();
	this->mBarSelectSize = new SDL_Rect();


	*this->mBarSelectDiff = { this->mBtnTxtEasy->get_dest().x, this->mBtnTxtEasy->get_dest().y + this->mBtnTxtEasy->get_dest().h , 0, 10 };
	*this->mBarSelectSize = { this->mBtnTxtSmall->get_dest().x, this->mBtnTxtSmall->get_dest().y + this->mBtnTxtSmall->get_dest().h, 0, 10};

	std::string path = "Ressources/Image/Default/barSelect.png";
	SDL_Surface* surface = IMG_Load(path.c_str());
	this->textureBar = SDL_CreateTextureFromSurface(this->mRenderer, surface);
	SDL_FreeSurface(surface);

	this->mWallpaper = new WallPaper(128, 128, this->width, this->height, "Ressources/Image/Default/Background_Repeat_01.png", this->mRenderer);


}


void SettingGame::draw()
{
	//std::cout << "SttingGame draw" << std::endl;
	///afficher le fond d'eranc'
	this->mWallpaper->draw();

	//Afficher les boutton
	this->mBtnTxtEasy->draw();
	this->mBtnTxtAverage->draw();
	this->mBtnTxtHard->draw();
	this->mBtnTxtSmall->draw();
	this->mBtnTxtMedium->draw();
	this->mBtnTxtLarge->draw();
	this->mBtnTxtPlay->draw();
	//afficher les Texts
	this->mDifficutyTxt->draw();
	this->mSizeTxt->draw();

	SDL_RenderCopy(this->mRenderer, this->textureBar, this->m_srcBar, this->mBarSelectDiff);
	SDL_RenderCopy(this->mRenderer, this->textureBar, this->m_srcBar, this->mBarSelectSize);

}


SettingGame::~SettingGame()
{
}

void SettingGame::input(SDL_Event eventListener)
{
	this->mBtnTxtEasy->input(eventListener);
	this->mBtnTxtAverage->input(eventListener);
	this->mBtnTxtHard->input(eventListener);
	this->mBtnTxtSmall->input(eventListener);
	this->mBtnTxtMedium->input(eventListener);
	this->mBtnTxtLarge->input(eventListener);
	this->mBtnTxtPlay->input(eventListener);

	if (mBtnTxtEasy->get_action())
	{
		this->action = ACTION_SET_EASY;
		this->mBtnTxtEasy->set_action(false);
		this->mBtnTxtAverage->set_action(false);
		this->mBtnTxtHard->set_action(false);
		*this->mBarSelectDiff = { this->mBtnTxtEasy->get_dest().x, this->mBtnTxtEasy->get_dest().y + this->mBtnTxtLarge->get_dest().h + 5, this->mBtnTxtEasy->get_dest().w, this->mBarSelectDiff->h };
	}
	else if (mBtnTxtAverage->get_action())
	{
		this->action = ACTION_SET_AVG;
		this->mBtnTxtEasy->set_action(false);
		this->mBtnTxtAverage->set_action(false);
		this->mBtnTxtHard->set_action(false);
		*this->mBarSelectDiff = { this->mBtnTxtAverage->get_dest().x, this->mBtnTxtAverage->get_dest().y + this->mBtnTxtLarge->get_dest().h + 5, this->mBtnTxtEasy->get_dest().w, this->mBarSelectDiff->h };
	}
	else if (mBtnTxtHard->get_action())
	{
		this->action = ACTION_SET_HARD;
		this->mBtnTxtEasy->set_action(false);
		this->mBtnTxtAverage->set_action(false);
		this->mBtnTxtHard->set_action(false);
		*this->mBarSelectDiff = { this->mBtnTxtHard->get_dest().x, this->mBtnTxtHard->get_dest().y + this->mBtnTxtLarge->get_dest().h + 5, this->mBtnTxtEasy->get_dest().w, this->mBarSelectDiff->h };
	}
 if (mBtnTxtSmall->get_action())
	{
		this->action = ACTION_SET_SMALL;
		this->mBtnTxtSmall->set_action(false);
		this->mBtnTxtMedium->set_action(false);
		this->mBtnTxtLarge->set_action(false);
		*this->mBarSelectSize = { this->mBtnTxtSmall->get_dest().x, this->mBtnTxtSmall->get_dest().y + this->mBtnTxtLarge->get_dest().h + 5, this->mBtnTxtEasy->get_dest().w, this->mBarSelectSize->h };
	}
	else if (mBtnTxtMedium->get_action())
	{
		this->action = ACTION_SET_MED;
		this->mBtnTxtSmall->set_action(false);
		this->mBtnTxtMedium->set_action(false);
		this->mBtnTxtLarge->set_action(false);
		*this->mBarSelectSize = { this->mBtnTxtMedium->get_dest().x, this->mBtnTxtMedium->get_dest().y + this->mBtnTxtLarge->get_dest().h + 5, this->mBtnTxtEasy->get_dest().w, this->mBarSelectSize->h };

	}
	else if (mBtnTxtLarge->get_action())
	{
		this->action = ACTION_SET_LARGE;
		this->mBtnTxtSmall->set_action(false);
		this->mBtnTxtMedium->set_action(false);
		this->mBtnTxtLarge->set_action(false);
		*this->mBarSelectSize = { this->mBtnTxtLarge->get_dest().x, this->mBtnTxtLarge->get_dest().y + this->mBtnTxtLarge->get_dest().h + 5 , this->mBtnTxtEasy->get_dest().w, this->mBarSelectSize->h };
	}
 if (mBtnTxtPlay->get_action())
 {
	 this->action = ACTION_TO_INGAME;
 }
}





void SettingGame::windowSizeChanged(int width,int height)
{
	int margeBtnDiff = (width - (this->mbtnTxtEasy->get_dest().w + this->mBtnTxtAverage->get_dest().w + this->mBtnTxtHard->get_dest().w))/3
	int margeBtnSize = (width - (this->mbtnTxtSmall->get_dest().w + this->mBtnTxtMedium->get_dest().w + this->mBtnTxtLarge->get_dest().w)) / 3


	this->mBtnTxtEasy->changePos(margeBtnDiff, this->mDifficutyTxt->get_rect_dest().y + 30);
	this->mBtnTxtAverage->changePos(this->mBtnTxtEasy->get_dest().x + this->mBtnTxtEasy->get_dest().w + margeBtnDiff, this->mDifficutyTxt->get_rect_dest().y + 30);
	this->mBtnTxtHard->changePos(this->mBtnTxtAverage->get_dest().x + this->mBtnTxtAverage->get_dest().w + margeBtnDiff, this->mDifficutyTxt->get_rect_dest().y + 30);

	if(this->mBtnTxtEasy->get_action())
	*this->mBarSelectDiff = { this->mBtnTxtEasy->get_dest().x, this->mBtnTxtEasy->get_dest().y - 20, this->mBarSelectDiff->w, this->mBarSelectDiff->h };
	else if (this->mBtnTxtAverage->get_action())
	*this->mBarSelectDiff = { this->mBtnTxtAverage->get_dest().x, this->mBtnTxtAverage->get_dest().y - 20, this->mBarSelectDiff->w, this->mBarSelectDiff->h };
	else if (this->mBtnTxtHard->get_action())
	*this->mBarSelectDiff = { this->mBtnTxtHard->get_dest().x, this->mBtnTxtHard->get_dest().y - 20, this->mBarSelectDiff->w, this->mBarSelectDiff->h };

	this->mBtnTxtSmall->changePos(margeBtnSize, this->mSizeTxt->get_rect_dest().y + 30);
	this->mBtnTxtMedium->changePos(this->mBtnTxtSmall->get_dest().x + this->mBtnTxtSmall->get_dest().w + margeBtnSize, this->mSizeTxt->get_rect_dest().y + 30);
	this->mBtnTxtLarge->changePos(this->mBtnTxtMedium->get_dest().x + this->mBtnTxtMedium->get_dest().w +margeBtnSize, this->mSizeTxt->get_rect_dest().y + 30);
	if (this->mBtnTxtSmall->get_action())
	*this->mBarSelectSize = { this->mBtnTxtSmall->get_dest().x, this->mBtnTxtSmall->get_dest().y - 20, this->mBarSelectSize->w, this->mBarSelectSize->h };
	else if (this->mBtnTxtMedium->get_action())
	*this->mBarSelectSize = { this->mBtnTxtMedium->get_dest().x, this->mBtnTxtMedium->get_dest().y - 20, this->mBarSelectSize->w, this->mBarSelectSize->h };
	else if (this->mBtnTxtHard->get_action())
	*this->mBarSelectSize = { this->mBtnTxtLarge->get_dest().x, this->mBtnTxtLarge->get_dest().y - 20, this->mBarSelectSize->w, this->mBarSelectSize->h };

}



void SettingGame::set_mineSettings(MinefieldSettings mineSettings )
{
	 this->mMineSettings = mineSettings;
}



