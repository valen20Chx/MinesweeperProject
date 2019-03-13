#include "MainMenu.h"



MainMenu::MainMenu(SDL_Renderer * pRenderer, int x, int y, int width, int height):Scene(pRenderer,x, y, width, height)
{
	//this->mWallpaper = new WallPaper(imgWidth, imgHeight, this->width, this->height, path, this->mRenderer);
	//this->mWallpaper->setImage(path);

	this->mBtnTxtSolo = new ButtonText({ 0, 0, 64, 16 }, { 200, 300, 32, 70 }, pRenderer, 10, 10, nullptr, "Ressources/Image/Default/Button_Default_Empty_Rest.png", "Ressources/Image/Default/Button_Default_Empty_Pressed.png", 16, { 100,100,255, 255 }, "Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "Solo");

	mBtnTxtMulti = new ButtonText({ 0, 0, 64, 16 }, { 200, 300, 32, 70 }, pRenderer, 10, 10, nullptr, "Ressources/Image/Default/Button_Default_Empty_Rest.png", "Ressources/Image/Default/Button_Default_Empty_Pressed.png", 16, { 100,100,255, 255 }, "Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "Multi");


	this->mBtnFermer = new Button({ 0, 0, 16, 16 }, { this->width -(this->width / 16) - 2, 2, this->width / 16, this->height / 16 }, true, nullptr, "Ressources/Image/Default/Button_Default_Empty_Rest.png", "Ressources/Image/Default/Button_Default_Empty_Pressed.png", this->mRenderer);
}

void MainMenu::update(int width, int height)
{
    //this->mWallPaper->update(width, height);
    this->mBtnFermer->updateBtnPos(width, height);
    this->mBtnTxtSolo->updateBtnPos(width, height);
    this->mBtnTxtMulti->updateBtnPos(width, height);

}

void MainMenu::draw()
{
   // this->mWpp->draw();
    this->mBtnFermer->draw();
    this->mBtnTxtSolo->draw();
    this->mBtnTxtMulti->draw();
}

MainMenu::~MainMenu()
{
}
