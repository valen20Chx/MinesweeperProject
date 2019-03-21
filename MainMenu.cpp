#include "MainMenu.h"


MainMenu::MainMenu(SDL_Renderer * pRenderer, int x, int y, int width, int height) : Scene(pRenderer,x, y, width, height)
{
	this->mWallpaper = new WallPaper(128, 128, this->width, this->height, "Ressources/Image/Default/Background_Repeat_01.png", this->mRenderer);

	SDL_Rect* btnSoloRect = new SDL_Rect();
	*btnSoloRect = { width/2 - 50, height/4, 100, 50 };
	this->mBtnTxtSolo = new ButtonText(NULL, btnSoloRect, this->mRenderer,	BUTTON_REST, BUTTON_PRESSED,32, { 100, 100, 255, 255 }, FONT_BOLD, "Solo");

	SDL_Rect* btnMultiRect = new SDL_Rect();
	*btnMultiRect = { width/2 - 60, height/5*3, 120, 50 };
	this->mBtnTxtMulti = new ButtonText(NULL, btnMultiRect, this->mRenderer,
		BUTTON_REST, BUTTON_PRESSED,32, { 100,100,255, 255 }, FONT_BOLD, "Multi");

	SDL_Rect* btnFermerRect = new SDL_Rect();
	*btnFermerRect = { this->width - 34, 2, 32, 32 };
	this->mBtnFermer = new Button(NULL, btnFermerRect, BUTTON_QUIT_REST, BUTTON_QUIT_PRESSED, this->mRenderer);
}

void MainMenu::windowSizeChanged(int width, int height)
{
	// TODO : A refaire avec nouvelle methode
	this->mWallpaper->update(width, height);
    //this->mBtnFermer-> // set rect or pos...
    //this->mBtnTxtSolo-> // set re...
    //this->mBtnTxtMulti-> // ...
}

void MainMenu::draw()
{
	this->mWallpaper->draw();
    this->mBtnFermer->draw();
    this->mBtnTxtSolo->draw();
    this->mBtnTxtMulti->draw();
}

void MainMenu::input(SDL_Event eventListener)
{
	this->mBtnFermer->input(eventListener);
	this->mBtnTxtMulti->input(eventListener);
	this->mBtnTxtSolo->input(eventListener);

	if (this->mBtnFermer->get_action())
	{
		this->action = ACTION_QUITTER;
	}
	if (this->mBtnTxtSolo->get_action())
	{
		this->action = ACTION_TO_SETTINGS_GAME;
	}
	if (this->mBtnTxtMulti->get_action())
	{
		this->action = ACTION_TO_CONNECTION;
	}
}

MainMenu::~MainMenu()
{
}
