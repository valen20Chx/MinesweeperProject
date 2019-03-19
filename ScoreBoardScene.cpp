#include "ScoreBoardScene.h"

ScoreBoardScene::ScoreBoardScene(SDL_Renderer* pRenderer, int x, int y, int width, int height, 
	GameResult game_Result) : Scene(pRenderer, x, y, width, height)
{
	std::cout << "CONSTRUCTION SCOREBOARD" << std::endl;
	SDL_Rect* btnHomeRect = new SDL_Rect();
	*btnHomeRect = { this->width / 2 - 64, 2, 70, 32 };
	this->btnTxtHome = new ButtonText(NULL, btnHomeRect, pRenderer, BUTTON_REST, BUTTON_PRESSED, 16, VANILLE, FONT_BOLD, "HOME");

	SDL_Rect* btnQuitRect = new SDL_Rect();
	*btnQuitRect = { this->width - 34, 2, 32, 32 };
	this->btnQuit = new Button(NULL, btnQuitRect, BUTTON_QUIT_REST,
		BUTTON_QUIT_PRESSED, this->mRenderer);

	this->mWallPaper = new WallPaper(32, 32, this->width, this->height, "Ressources/Image/Default/Background_Repeat_01.png", this->mRenderer);

	this->txtListStats.push_back(new Text(this->mRenderer, 50, this->height / 3, 24, { 255,255,255,255 },
		FONT_BOLD, "Temps :"));
	this->txtListStats.push_back(new Text(this->mRenderer, 60 + this->txtListStats[0]->get_rect_dest().w,
		this->height / 3, 24, { 255,255,255,255 }, FONT_BOLD, std::to_string(this->game_Result.time) + " ms"));
	this->txtListStats.push_back(new Text(this->mRenderer, 50, this->height / 3 + 200, 24, { 255,255,255,255 },
		FONT_BOLD, "Nb Bombes :"));
	this->txtListStats.push_back(new Text(this->mRenderer, 60 + this->txtListStats[2]->get_rect_dest().w,
		this->height / 3, 24, { 255,255,255,255 }, FONT_BOLD, std::to_string(this->game_Result.nbBomb)));

	if (this->game_Result.won)
	{
		this->txtListStats.push_back(new Text(this->mRenderer, this->width/2 - 100,
			40, 40, { 255,255,255,255 }, FONT_BOLD, "Gagnant!"));
	}
	else
	{
		this->txtListStats.push_back(new Text(this->mRenderer, this->width / 2 - 100,
			40, 40, { 255,255,255,255 }, FONT_BOLD, "Perdant"));
	}


}

ScoreBoardScene::~ScoreBoardScene()
{
}

void ScoreBoardScene::input(Uint32 eventType)
{
	this->btnTxtHome->input(eventType);
	this->btnQuit->input(eventType);

	if(this->btnTxtHome->get_action())
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
	this->btnTxtHome->changeRect((this->width / 2) - 8, 10, 16, 16);

	this->txtListStats[0]->set_rect_dest(this->txtListStats[0]->get_rect_dest().x, this->height / 3);
	this->txtListStats[1]->set_rect_dest(this->txtListStats[1]->get_rect_dest().x, this->height / 3);
	this->txtListStats[2]->set_rect_dest(this->txtListStats[2]->get_rect_dest().x, this->height / 3 + 200);
	this->txtListStats[3]->set_rect_dest(this->txtListStats[3]->get_rect_dest().x, this->height / 3 + 200);
	this->txtListStats[4]->set_rect_dest((this->width / 2) - (this->txtListStats[4]->get_rect_dest().w / 2), 40);
}

void ScoreBoardScene::draw()
{
	this->mWallPaper->draw();
	this->btnQuit->draw();
	this->btnTxtHome->draw();
}
