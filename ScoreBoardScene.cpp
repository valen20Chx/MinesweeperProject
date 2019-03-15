#include "ScoreBoardScene.h"

ScoreBoardScene::ScoreBoardScene(SDL_Renderer* pRenderer, int x, int y, int width, int height, 
	Game_Result game_Result) : Scene(pRenderer, x, y, width, height)
{
	this->game_Result = game_Result;

	SDL_Rect btnHomeRect = { (this->width / 2) - 8, 10, 16, 16 };
	this->btnHome = new Button(NULL, &btnHomeRect, "Ressources/Image/Default/Button_Home_Rest.png",
		"Ressources/Image/Default/Button_Home_Pressed.png", this->mRenderer);

	SDL_Rect btnQuitRect = { this->width - 10, 10, 16, 16 };
	this->btnQuit = new Button(NULL, &btnQuitRect, "Ressources/Image/Default/Button_Quit_Rest.png",
		"Ressources/Image/Default/Button_Quit_Pressed.png", this->mRenderer);

	this->mWallPaper = new WallPaper(32, 32, this->width, this->height, "Ressources/Image/Default/Background_Repeat_01.png", this->mRenderer);

	this->txtListStats.push_back(new Text(this->mRenderer, 50, this->height / 3, 24, { 255,255,255,255 },
		"Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "Temps :"));
	this->txtListStats.push_back(new Text(this->mRenderer, 60 + this->txtListStats[0]->get_rect_dest().w,
		this->height / 3, 24, { 255,255,255,255 }, "Ressources/Font/Open_Sans/OpenSans-Bold.ttf", std::to_string(this->game_Result.temps) + " ms"));
	this->txtListStats.push_back(new Text(this->mRenderer, 50, this->height / 3 + 200, 24, { 255,255,255,255 },
		"Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "Nb Bombes :"));
	this->txtListStats.push_back(new Text(this->mRenderer, 60 + this->txtListStats[2]->get_rect_dest().w,
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

void ScoreBoardScene::input(Uint32 eventType)
{
	this->btnHome->input(eventType);
	this->btnQuit->input(eventType);

	if(this->btnHome->get_action())
	{
		this->action = ACTION_TO_MENU; // to mainmenu
	}
	if(this->btnQuit->get_action())
	{
		this->action = ACTION_QUITTER; // quitter le jeu
	}
}

void ScoreBoardScene::windowSizeChanged(int width, int height)
{
	this->width = width;
	this->height = height;

	this->btnQuit->changeRect(this->width - 10, 10, 16, 16);
	this->btnHome->changeRect((this->width / 2) - 8, 10, 16, 16);

	this->txtListStats[0]->set_rect_dest(this->txtListStats[0]->get_rect_dest().x, this->height / 3);
	this->txtListStats[1]->set_rect_dest(this->txtListStats[1]->get_rect_dest().x, this->height / 3);
	this->txtListStats[2]->set_rect_dest(this->txtListStats[2]->get_rect_dest().x, this->height / 3 + 200);
	this->txtListStats[3]->set_rect_dest(this->txtListStats[3]->get_rect_dest().x, this->height / 3 + 200);
	this->txtListStats[4]->set_rect_dest((this->width / 2) - (this->txtListStats[4]->get_rect_dest().w / 2), 40);
}