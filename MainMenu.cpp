#include "MainMenu.h"


MainMenu::MainMenu(SDL_Renderer * pRenderer, int x, int y, int width, int height) : Scene(pRenderer,x, y, width, height)
{
	this->mWallpaper = new WallPaper(128, 128, this->width, this->height, "Ressources/Image/Default/Background_Repeat_01.png", this->mRenderer);

	SDL_Rect* btnSoloRect = new SDL_Rect();
	*btnSoloRect = { 200, 300, 32, 70 };
	this->mBtnTxtSolo = new ButtonText(NULL, btnSoloRect, this->mRenderer,
		"Ressources/Image/Default/Button_Default_Empty_Rest.png", "Ressources/Image/Default/Button_Default_Empty_Pressed.png",
		32, { 100, 100, 255, 255 }, "Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "Solo");

	SDL_Rect* btnMultiRect = new SDL_Rect();
	*btnMultiRect = { 0, 300, 32, 70 };
	this->mBtnTxtMulti = new ButtonText(NULL, btnMultiRect, this->mRenderer,
		"Ressources/Image/Default/Button_Default_Empty_Rest.png", "Ressources/Image/Default/Button_Default_Empty_Pressed.png", 
		32, { 100,100,255, 255 }, "Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "Multi");

	SDL_Rect* btnFermerRect = new SDL_Rect();
	*btnFermerRect = { this->width - 96, 32, 32, 32 };
	this->mBtnFermer = new Button(NULL, btnFermerRect, "Ressources/Image/Default/Button_Quit_Rest.png",
		"Ressources/Image/Default/Button_Quit_Pressed.png", this->mRenderer);
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

void MainMenu::input(Uint32 eventType)
{
	this->mBtnFermer->input(eventType);
	this->mBtnTxtMulti->input(eventType);
	this->mBtnTxtSolo->input(eventType);
}

MainMenu::~MainMenu()
{
}
