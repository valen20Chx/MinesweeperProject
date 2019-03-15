#include "StateInGame.h"

StateInGame::StateInGame(SDL_Renderer * pRenderer, int x, int y, int width, int height, MinefieldSettings mineFieldSettings):Scene(pRenderer,x, y, width, height)
{
	SDL_Rect btnParamRect = { 100, 2, 32, 32 };
	this->btnParam = new Button(NULL, &btnParamRect,
		"Ressources/Image/Default/Button_Option_Rest.png", "Ressources/Image/Default/Button_Option_Pressed.png", pRenderer);

	SDL_Rect btnHomeRect = { 200, 2, 32, 70 };
	this->btnTxtHome = new ButtonText(NULL, &btnHomeRect, pRenderer,
		 "Ressources/Image/Default/Button_Default_Empty_Rest.png",
		"Ressources/Image/Default/Button_Default_Empty_Pressed.png", 16, { 100,100,255, 255 }, 
		"Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "Home");

	SDL_Rect btnRestartRect = { 300, 2, 32, 70 };
	this->btnTxtResart = new ButtonText(NULL, &btnRestartRect, pRenderer,
		 "Ressources/Image/Default/Button_Default_Empty_Rest.png",
		"Ressources/Image/Default/Button_Default_Empty_Pressed.png", 16, { 100,100,255, 255 },
		"Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "Restart");
	
	SDL_Rect btnFermerRect = { this->width - (this->width / 16) - 2, 2, this->width / 16, this->height / 16 };
	this->btnFermer = new Button(NULL, &btnFermerRect,"Ressources/Image/Default/Button_Quit_Rest.png",
		"Ressources/Image/Default/Button_Quit_Pressed.png", this->mRenderer);


	// TODO : generation variable!!!
	this->gameGrid = new MineField(10, 10, 5, 123);
	this->gameGrid->set_Squares(width, height, pRenderer);
}
	
StateInGame::~StateInGame()
{
}

void StateInGame::windowSizeChanged(int width, int height)
{
	// TODO : a refaire avec nouvelle methode
	//this->btnParam->updateBtnPos(width, height);
	//this->btnTxtHome->updateBtnTxtPos(width, height);
	//this->btnTxtResart->updateBtnTxtPos(width, height);
}

void StateInGame::draw()
{
	this->gameGrid->draw(this->mRenderer);
	this->btnParam->draw();
	this->btnTxtHome->draw();
	this->btnTxtResart->draw();
	this->btnFermer->draw();
}

void StateInGame::input(Uint32 eventType)
{
	this->btnFermer->input(eventType);
	this->btnParam->input(eventType);
	this->btnTxtHome->input(eventType);
	this->btnTxtResart->input(eventType);
	this->gameGrid->input(eventType, this->width, this->height);
}

MinefieldSettings StateInGame::get_gameResult()
{
	return {this->gameGrid->get_}; // TODO : remplir structure
}