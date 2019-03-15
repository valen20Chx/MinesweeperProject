#include "SettingGame.h"



SettingGame::SettingGame(SDL_Renderer * pRenderer, int x, int y, int width, int height, MinefieldSettings* mineSettings):Scene(pRenderer, x, y, width, height)
{
	SDL_Rect btnEasyRect = { width / 5, width / 3, 70, 70 };
	this->mBtnTxtEasy = new ButtonText(NULL, &btnEasyRect, this->mRenderer,
		"Ressources/Image/Default/Button_Default_Empty_Rest.png",
		"Ressources/Image/Default/Button_Default_Empty_Pressed.png", 18, { 100,100,255, 255 },
		"Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "EASY");

	SDL_Rect btnAvgRect = { width / 5 * 2, width / 3, 70, 70 };
	this->mBtnTxtAverage = new ButtonText(NULL, &btnAvgRect, this->mRenderer,
		"Ressources/Image/Default/Button_Default_Empty_Rest.png",
		"Ressources/Image/Default/Button_Default_Empty_Pressed.png", 18, { 100,100,255, 255 },
		"Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "AVERAGE");

	SDL_Rect btnHardRect = { width / 5 * 4, width / 3, 70, 70 };
	this->mBtnTxtHard = new ButtonText(NULL, &btnHardRect, this->mRenderer,
		"Ressources/Image/Default/Button_Default_Empty_Rest.png",
		"Ressources/Image/Default/Button_Default_Empty_Pressed.png", 18, { 100,100,255, 255 },
		"Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "HARD");

	SDL_Rect btnSmallRect = { width / 5, width / 2, 70, 70 };
	this->mBtnTxtSmall = new ButtonText(NULL, &btnSmallRect, this->mRenderer,
		"Ressources/Image/Default/Button_Default_Empty_Rest.png",
		"Ressources/Image/Default/Button_Default_Empty_Pressed.png", 18, { 100,100,255, 255 },
		"Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "SMALL");

	SDL_Rect btnMedRect = { width / 5 * 2, width / 2, 70, 70 };
	this->mBtnTxtMedium = new ButtonText(NULL, &btnMedRect, this->mRenderer,
		"Ressources/Image/Default/Button_Default_Empty_Rest.png",
		"Ressources/Image/Default/Button_Default_Empty_Pressed.png", 18, { 100,100,255, 255 },
		"Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "MEDIUM");

	SDL_Rect btnLargeRect = { width / 5 * 4, width / 2, 70, 70 };
	this->mBtnTxtLarge = new ButtonText(NULL, &btnLargeRect, this->mRenderer,
		"Ressources/Image/Default/Button_Default_Empty_Rest.png",
		"Ressources/Image/Default/Button_Default_Empty_Pressed.png", 18, { 100,100,255, 255 },
		"Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "LARGE");

	//Charger les Text
	this->mDifficutyTxt = new Text(this->mRenderer, this->width / 2 - 30, this->height / 20, 24, { 100,100,100,255 }, "Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "DIFFICULTY");
	this->mSizeTxt = new Text(this->mRenderer, this->width / 2 - 30, this->height / 5, 24, { 100,100,100,255 }, "Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "SIZE");

	//Charger les Bar de seletection
	std::string path = "Ressources/Image/Default/barSelect.png";
	SDL_Surface* surface = IMG_Load(path.c_str());
	this->textureBar = SDL_CreateTextureFromSurface(this->mRenderer, surface);
	SDL_FreeSurface(surface);

}


void SettingGame::draw()
{
	//Afficher les boutton
	this->mBtnTxtEasy->draw();
	this->mBtnTxtAverage->draw();
	this->mBtnTxtHard->draw();
	this->mBtnTxtSmall->draw();
	this->mBtnTxtMedium->draw();
	this->mBtnTxtLarge->draw();
	//afficher les Texts
	this->mDifficutyTxt->draw();
	this->mSizeTxt->draw();

	SDL_RenderCopy(this->mRenderer, this->textureBar, this->m_srcBar, this->mBarSelectDiff);
	SDL_RenderCopy(this->mRenderer, this->textureBar, this->m_srcBar, this->mBarSelectSize);

}

void SettingGame::input(Uint32 eventType) {
	this->mBtnTxtEasy->input(eventType);
	this->mBtnTxtAverage->input(eventType);
	this->mBtnTxtHard->input(eventType);
	this->mBtnTxtSmall->input(eventType);
	this->mBtnTxtMedium->input(eventType);
	this->mBtnTxtLarge->input(eventType);

	if (this->mBtnTxtEasy->get_action() == true)
	{
		this->mMineSettings.percentBomb = 10;

		this->mBtnTxtAverage->set_action(false);
		this->mBtnTxtHard->set_action(false);

		this->set_paramRect(mBarSelectDiff, this->mBtnTxtEasy->get_dest().x, this->mBtnTxtEasy->get_dest().y - 20, this->mBarSelectDiff->w, this->mBarSelectDiff->h);
	}
	if (this->mBtnTxtAverage->get_action() == true)
	{
		this->mMineSettings.percentBomb = 20;

		this->mBtnTxtEasy->set_action(false);
		this->mBtnTxtHard->set_action(false);

		this->set_paramRect(mBarSelectDiff, this->mBtnTxtAverage->get_dest().x, this->mBtnTxtAverage->get_dest().y - 20, this->mBarSelectDiff->w, this->mBarSelectDiff->h);
	}

	if (this->mBtnTxtHard->get_action() == true)
	{
		this->mMineSettings.percentBomb = 30;

		this->mBtnTxtEasy->set_action(false);
		this->mBtnTxtAverage->set_action(false);

		this->set_paramRect(mBarSelectDiff, this->mBtnTxtHard->get_dest().x, this->mBtnTxtHard->get_dest().y - 20, this->mBarSelectDiff->w, this->mBarSelectDiff->h);
	}

	if (this->mBtnTxtSmall->get_action() == true)
	{
		this->mMineSettings.width = 7;
		this->mMineSettings.height = 7;
	
		this->mBtnTxtMedium->set_action(false);
		this->mBtnTxtLarge->set_action(false);

		this->set_paramRect(mBarSelectSize, this->mBtnTxtSmall->get_dest().x, this->mBtnTxtSmall->get_dest().y - 20, this->mBarSelectSize->w, this->mBarSelectSize->h);

	}

	if (this->mBtnTxtMedium->get_action() == true)
	{
		this->mMineSettings.width = 10;
		this->mMineSettings.height = 10;

		this->mBtnTxtSmall->set_action(false);
		this->mBtnTxtLarge->set_action(false);

		this->set_paramRect(mBarSelectSize, this->mBtnTxtMedium->get_dest().x, this->mBtnTxtMedium->get_dest().y - 20, this->mBarSelectSize->w, this->mBarSelectSize->h);
	}

	if (this->mBtnTxtLarge->get_action() == true)
	{
		this->mMineSettings.width = 14;
		this->mMineSettings.height = 14;

		this->mBtnTxtSmall->set_action(false);
		this->mBtnTxtMedium->set_action(false);

		this->set_paramRect(mBarSelectSize, this->mBtnTxtLarge->get_dest().x, this->mBtnTxtLarge->get_dest().y - 20, this->mBarSelectSize->w, this->mBarSelectSize->h);
	}
}

void SettingGame::set_paramRect(SDL_Rect* rect, int x, int y, int w, int h)
{
	rect->x = x;
	rect->y = y;
	rect->w = w;
	rect->h = h;
}

SettingGame::~SettingGame()
{
}


