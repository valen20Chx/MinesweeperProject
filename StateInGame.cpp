#include "StateInGame.h"

StateInGame::StateInGame(SDL_Renderer * pRenderer, int x, int y, int width, int height, MinefieldSettings mineFieldSettings):Scene(pRenderer,x, y, width, height)
{

	SDL_Rect* btnHomeRect = new SDL_Rect();
	*btnHomeRect = { this->width / 2 - 35, 2, 70, 32 };
	this->btnTxtHome = new ButtonText(NULL, btnHomeRect, pRenderer, BUTTON_REST,BUTTON_PRESSED, 16, BLACK, FONT_BOLD, "HOME");
	
	/*SDL_Rect* btnRestartRect = new SDL_Rect();
	*btnRestartRect = { this->width /4, 2, 70, 32 };
	this->btnTxtResart = new ButtonText(NULL, btnRestartRect, pRenderer,BUTTON_REST, BUTTON_PRESSED, 16, BLACK, FONT_BOLD, "Restart");*/
	

	SDL_Rect* btnFermerRect = new SDL_Rect();
	*btnFermerRect = { this->width - 34, 2, 32, 32};
	this->btnFermer = new Button(NULL, btnFermerRect, BUTTON_QUIT_REST, BUTTON_QUIT_PRESSED, this->mRenderer);

	this->gameGrid = new MineField(mineFieldSettings);
	this->gameGrid->set_Squares(width, height, pRenderer);
}
	
StateInGame::~StateInGame()
{
}

void StateInGame::windowSizeChanged(int width, int height)
{
	this->btnTxtHome->changePos(width / 2 - 35, 2);
	//this->btnTxtResart->changePos(width / 3 * 2, height - 50);
	this->btnFermer->changePos(width - 3, 2);
}

void StateInGame::draw()
{
	//std::cout << "IN game draw" << std::endl;

	this->gameGrid->draw(this->mRenderer);
	this->btnTxtHome->draw();
	//this->btnTxtResart->draw();
	this->btnFermer->draw();
}

void StateInGame::input(Uint32 eventType)
{
	this->btnFermer->input(eventType);
	this->btnTxtHome->input(eventType);
	//this->btnTxtResart->input(eventType);
	this->gameGrid->input(eventType, this->width, this->height);

	if (this->btnFermer->get_action())
	{
		this->action = ACTION_QUITTER;
	}
	else if(this->btnTxtHome->get_action())
	{
		this->action = ACTION_TO_MENU;
	}
	if (this->gameGrid->get_isFinished() == true)
	{
		set_gameResult();
		std::cout << "bomb " << this->game_Result.nbBomb << std::endl;
		std::cout << "flag " << this->game_Result.nbGoodFlag << std::endl;
		std::cout << "time " << this->game_Result.time << std::endl;
		std::cout << "win or loos " << this->game_Result.won << std::endl;

		
		std::cout << "FIN de partie" << std::endl;
		this->action = ACTION_TO_SCOREBOARD;
	}
}

void StateInGame::set_gameResult()
{
	this->gameGrid->set_nbGoodFlag();
	this->game_Result.nbGoodFlag = this->gameGrid->get_nbGoodFlag();
	this->game_Result.nbBomb = this->gameGrid->get_nbBomb();
	this->game_Result.won = this->gameGrid->get_isWon();
	this->game_Result.time = this->gameGrid->getRuningTicks();
}