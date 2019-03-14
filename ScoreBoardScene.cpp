#include "ScoreBoardScene.h"

ScoreBoardScene::ScoreBoardScene(SDL_Renderer* pRenderer, int x, int y, int width, int height,
	void(*quitFunc)(), void(*homeFunc)(), Game_Result game_Result) : Scene(pRenderer, x, y, width, height)
{
	this->game_Result = game_Result;

	this->btnHome = new Button({ 0, 0, 16, 16 }, { (this->width/2) - 8, 10, 16, 16},
		true, homeFunc, "Ressources/Image/Default/Button_Home_Rest.png",
		"Ressources/Image/Default/Button_Home_Pressed.png", this->mRenderer);

	this->btnQuit = new Button({ 0, 0, 16, 16 }, { this->width - 10, 10, 16, 16 },
		true, quitFunc, "Ressources/Image/Default/Button_Quit_Rest.png",
		"Ressources/Image/Default/Button_Quit_Pressed.png", this->mRenderer);
	this->mWallPaper = new WallPaper(32, 32, this->width, this->height, "Ressources/Image/Default/Background_Repeat_01.png", this->mRenderer);

	this->txtListStats.push_back(new Text(this->mRenderer, 50, this->height / 3, 24, { 255,255,255,255 },
		"Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "Temps :"));
	this->txtListStats.push_back(new Text(this->mRenderer, 60 + this->txtListStats[0]->getDestRect().w,
		this->height / 3, 24, { 255,255,255,255 }, "Ressources/Font/Open_Sans/OpenSans-Bold.ttf", std::to_string(this->game_Result.temps) + " ms"));
	this->txtListStats.push_back(new Text(this->mRenderer, 50, this->height / 3 + 200, 24, { 255,255,255,255 },
		"Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "Nb Bombes :"));
	this->txtListStats.push_back(new Text(this->mRenderer, 60 + this->txtListStats[2]->getDestRect().w,
		this->height / 3, 24, { 255,255,255,255 }, "Ressources/Font/Open_Sans/OpenSans-Bold.ttf", std::to_string(this->game_Result.nbBombes)));
	if (this->game_Result.success)
	{
		this->txtListStats.push_back(new Text(this->mRenderer, this->width/2 - 100,
			40, 40, { 255,255,255,255 }, "Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "Gagnant!"));
	}
	else
	{
		this->txtListStats.push_back(new Text(this->mRenderer, this->width / 2 - 100,
			40, 40, { 255,255,255,255 }, "Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "Perdant"));
	}
}

ScoreBoardScene::~ScoreBoardScene()
{
}

void ScoreBoardScene::input(SDL_Event* eventListener)
{
	this->btnHome->input(eventListener);
	this->btnQuit->input(eventListener);
}

void ScoreBoardScene::updateWindowSize(int width, int height)
{
	this->width = width;
	this->height = height;

	this->btnQuit->set_dest(this->width - 10, 10, 16, 16);
	this->btnHome->set_dest((this->width / 2) - 8, 10, 16, 16);

	this->txtListStats[0]->set_rect_dest(this->txtListStats[0]->getDestRect().x, this->height / 3);
	this->txtListStats[1]->set_rect_dest(this->txtListStats[1]->getDestRect().x, this->height / 3);
	this->txtListStats[2]->set_rect_dest(this->txtListStats[2]->getDestRect().x, this->height / 3 + 200);
	this->txtListStats[3]->set_rect_dest(this->txtListStats[3]->getDestRect().x, this->height / 3 + 200);
	this->txtListStats[4]->set_rect_dest((this->width / 2) - (this->txtListStats[4]->getDestRect().w / 2), 40);
}