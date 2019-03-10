#include "StateInGame.h"

StateInGame::StateInGame(SDL_Renderer * pRenderer, int x, int y, int width, int height, void(*quitFunc)(), void(*mainMenuFunc)()):Scene(pRenderer,x, y, width, height)
{
	this->btnParam = new Button({ 0, 0, 16, 16 }, { 100, 2, 32, 32 },
		true, nullptr, "Ressources/Image/Default/Button_Option_Rest.png", "Ressources/Image/Default/Button_Option_Pressed.png", pRenderer);

	this->btnTxtHome = new ButtonText({ 0, 0, 64, 16 }, { 200, 2, 32, 70 }, pRenderer,
		10, 10, mainMenuFunc, "Ressources/Image/Default/Button_Default_Empty_Rest.png",
		"Ressources/Image/Default/Button_Default_Empty_Pressed.png", 16, { 100,100,255, 255 }, 
		"Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "Home");

	this->btnTxtResart = new ButtonText({ 0, 0, 64, 16 }, { 300, 2, 32, 70 }, pRenderer,
		10, 10, nullptr, "Ressources/Image/Default/Button_Default_Empty_Rest.png",
		"Ressources/Image/Default/Button_Default_Empty_Pressed.png", 16, { 100,100,255, 255 },
		"Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "Restart");
	
	this->btnFermer = new Button({ 0, 0, 16, 16 }, { this->width -(this->width / 16) - 2, 2, this->width / 16, this->height / 16 },
		true, quitFunc, "Ressources/Image/Default/Button_Quit_Rest.png", "Ressources/Image/Default/Button_Quit_Pressed.png", this->mRenderer);

	this->gameGrid = new MineField(10, 10, 5, 123);
	this->gameGrid->set_Squares(width, height, pRenderer);
}
	
StateInGame::~StateInGame()
{
}

void StateInGame::updateWindowSize(int W, int H)
{
	this->btnParam->updateBtnPos(W, H);
	this->btnTxtHome->updateBtnTxtPos(W, H);
	this->btnTxtResart->updateBtnTxtPos(W, H);
}

void StateInGame::draw()
{
	this->gameGrid->draw(this->mRenderer);
	this->btnParam->draw();
	this->btnTxtHome->draw();
	this->btnTxtResart->draw();
	this->btnFermer->draw();
}

void StateInGame::input(SDL_Event* eventListener)
{
	this->btnFermer->input(eventListener);
	this->btnParam->input(eventListener);
	this->btnTxtHome->input(eventListener);
	this->btnTxtResart->input(eventListener);
	this->gameGrid->input(eventListener, this->width, this->height);
}