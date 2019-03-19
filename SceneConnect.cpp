#include "SceneConnect.h"



SceneConnect::SceneConnect(SDL_Renderer * pRenderer, int x, int y, int width, int height):Scene(pRenderer, x, y, width, height)
{
	SDL_Rect btnTxtConnectRect = { width / 2 - 32, height / 4 * 3, 16, 64 };
	this->mBtnTxtConnect = new ButtonText(NULL, &btnTxtConnectRect, pRenderer, BUTTON_REST, BUTTON_PRESSED, 16, { 100,100,255, 255 }, FONT_BOLD, "Home");

	this->mTxtLogin = new Text(pRenderer, width / 2 - 32, height / 3 - 32, 16, BLACK, FONT_BOLD, "LOGIN");
	this->editLogin = new EditText(pRenderer, width/2 - 32, height / 3, 25);
	this->mTxtPass = new Text(pRenderer, width / 2 - 32, height / 3 * 2 - 32, 16, BLACK, FONT_BOLD, "LOGIN");
	this->editPass = new EditText(pRenderer, width / 2 - 32, height / 3 * 2, 25);
}


SceneConnect::~SceneConnect()
{
}
