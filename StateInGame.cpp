#include "StateInGame.h"



StateInGame::StateInGame(SDL_Renderer * pRenderer, int x, int y, int width, int height):Scene(pRenderer,x, y, width, height)
{
	this->btnParam = new Button({ 0, 0, 16, 16 }, { 100, 2, 32, 32 }, true, pRenderer);
	this->btnParam->setPath("Ressources/Image/Default/Button_Option_Rest.png", "Ressources/Image/Default/Button_Option_Pressed.png");

	this->btnTxtHome = new ButtonText({ 0, 0, 64, 16 }, { 200, 2, 32, 70 }, pRenderer, 10, 10, 16, { 100,100,255, 255 }, "Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "Home");
	this->btnTxtHome->setPath("Ressources/Image/Default/Button_Default_Empty_Rest.png", "Ressources/Image/Default/Button_Default_Empty_Pressed.png");

	this->btnTxtResart = new ButtonText({ 0, 0, 64, 16 }, { 300, 2, 32, 70 }, pRenderer, 10, 10, 16, { 100,100,255, 255 }, "Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "Restart");
	this->btnTxtResart->setPath("Ressources/Image/Default/Button_Default_Empty_Rest.png", "Ressources/Image/Default/Button_Default_Empty_Pressed.png");

	this->btnFermer = new Button({ 0, 0, 16, 16 }, { this->width -(this->width / 16) - 2, 2, this->width / 16, this->height / 16 }, true, this->mRenderer);
	this->btnFermer->setPath("Ressources/Image/Default/Button_Quit_Rest.png", "Ressources/Image/Default/Button_Quit_Pressed.png");

	this->gameGrid = new MineField(10, 10, 5, 123);
	this->gameGrid->set_Squares(width, height, pRenderer);
}

void StateInGame::Update(int W, int H) {
	this->btnParam->updateBtn(W, H);
	this->btnTxtHome->updateBtnTxt(W, H);
	this->btnTxtResart->updateBtnTxt(W, H);
}

	

StateInGame::~StateInGame()
{
}


void StateInGame::draw()
{
	this->gameGrid->draw(this->mRenderer);
	this->Update(this->width, this->height);
	

	this->btnParam->updateBtn(this->width, this->height);
	this->btnParam->draw();
	

	this->btnTxtHome->updateBtnTxt(this->width, this->height);
	this->btnTxtHome->draw();
	
	this->btnTxtResart->updateBtnTxt(this->width, this->height);
	this->btnTxtResart->draw();

	this->btnFermer->updateBtn(this->width, this->height);
	this->btnFermer->draw();
}

