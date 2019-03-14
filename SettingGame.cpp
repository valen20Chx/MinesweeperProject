#include "SettingGame.h"



SettingGame::SettingGame(SDL_Renderer * pRenderer, int x, int y, int width, int height, void(*ToInGameFc)(),MinefieldSettings* mineSettings):Scene(pRenderer, x, y, width, height)
{
	//Charger les boutton
	this->mBtnTxtEasy = new ButtonText({ 0, 0, 64, 16 }, { width/5, width/3, 70, 70 }, this->mRenderer,
		10, 10, nullptr, "Ressources/Image/Default/Button_Default_Empty_Rest.png",
		"Ressources/Image/Default/Button_Default_Empty_Pressed.png", 18, { 100,100,255, 255 },
		"Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "EASY");
	this->mBtnTxtAverage = new ButtonText({ 0, 0, 64, 16 }, { width / 5*2, width / 3, 70, 70 }, this->mRenderer,
		10, 10, nullptr, "Ressources/Image/Default/Button_Default_Empty_Rest.png",
		"Ressources/Image/Default/Button_Default_Empty_Pressed.png", 18, { 100,100,255, 255 },
		"Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "AVERAGE");
	this->mBtnTxtHard = new ButtonText({ 0, 0, 64, 16 }, { width / 5*4, width / 3, 70, 70 }, this->mRenderer,
		10, 10, nullptr, "Ressources/Image/Default/Button_Default_Empty_Rest.png",
		"Ressources/Image/Default/Button_Default_Empty_Pressed.png", 18, { 100,100,255, 255 },
		"Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "HARD");


	this->mBtnTxtSmall = new ButtonText({ 0, 0, 64, 16 }, { width / 5, width / 2, 70, 70 }, this->mRenderer,
		10, 10, nullptr, "Ressources/Image/Default/Button_Default_Empty_Rest.png",
		"Ressources/Image/Default/Button_Default_Empty_Pressed.png", 18, { 100,100,255, 255 },
		"Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "SMALL");
	this->mBtnTxtMedium = new ButtonText({ 0, 0, 64, 16 }, { width / 5*2, width / 2, 70, 70 }, this->mRenderer,
		10, 10, nullptr, "Ressources/Image/Default/Button_Default_Empty_Rest.png",
		"Ressources/Image/Default/Button_Default_Empty_Pressed.png", 18, { 100,100,255, 255 },
		"Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "MEDIUM");
	this->mBtnTxtLarge = new ButtonText({ 0, 0, 64, 16 }, { width / 5*4, width / 2, 70, 70 }, this->mRenderer,
		10, 10, nullptr, "Ressources/Image/Default/Button_Default_Empty_Rest.png",
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

void SettingGame::input(SDL_Event* eventListener) {
	this->mBtnTxtEasy->input(eventListener);
	this->mBtnTxtAverage->input(eventListener);
	this->mBtnTxtHard->input(eventListener);
	this->mBtnTxtSmall->input(eventListener);
	this->mBtnTxtMedium->input(eventListener);
	this->mBtnTxtLarge->input(eventListener);

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


