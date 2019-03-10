#include "Game.h"

Game::Game(std::string title, int width, int height, bool fullScreen)
{
	this->gameState = GAME_STATE_IN_GAME;
	this->fullScreen = fullScreen;
	this->width = width;
	this->height = height;
	this->isRunning = true;

	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();

	SDL_CreateWindowAndRenderer(this->width, this->height, SDL_WINDOW_RESIZABLE, &this->mWindow, &this->mRenderer);

	SDL_SetWindowTitle(this->mWindow, this->title.c_str());
	/*
	this->star.set_src(0, 0, 16, 16);
	this->star.set_dest(50, 50, 200, 200);
	this->star.setImage("Ressources/Image/book.png", this->mRenderer);
	*/
	


	this->mWallPaper = new WallPaper(32, 32, this->width, this->height, "Ressources/Image/Default/Background_Repeat_01.png", this->mRenderer);

	//this->monText = new Text(this->mRenderer, 100, 10, 40, {0, 62, 200, 255}, "Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "Test Message");

	
	this->inGame = new StateInGame(this->mRenderer, 0, 0, this->width, this->height);
	this->btnMenu = new ButtonText({ 0, 0, 64, 16 }, { 20, 200, 100, 30 }, this->mRenderer, 1, 300, 16, { 95, 255, 100, 255 }, "Ressources/Font/Open_Sans/OpenSans-Bold.ttf", "MENU");
	this->loop();
}

Game::~Game()
{
	SDL_DestroyRenderer(this->mRenderer);
	SDL_DestroyWindow(this->mWindow);

	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}

void Game::loop()
{
	while (this->isRunning)
	{
		this->lastFrame = SDL_GetTicks();
		static int lastTime;
		if (this->lastFrame >= (lastTime + 1000))
		{
			lastTime = this->lastFrame;
			this->frameCount = 0;
			this->count++;
		}

		this->render();
		this->input();
		this->update();

		this->draw(this->star);

		/*if (this->count > 3)
		{
			this->isRunning = false;
		}*/
	}
}

void Game::update()
{
}

void Game::input()
{
	SDL_Event eventListener;
	while (SDL_PollEvent(&eventListener))
	{
		if (eventListener.type == SDL_QUIT)
		{
			this->isRunning = false;
		}
		if (eventListener.type == SDL_MOUSEBUTTONDOWN)
		{
			SDL_GetMouseState(&this->mouseXpos, &this->mouseYpos);
			if (this->gameState == GAME_STATE_IN_GAME) {
				if (this->inGame->gameGrid->get_state() != MF_STATE_LOSS && this->inGame->gameGrid->get_state() != MF_STATE_WON)
				{
					if (eventListener.button.button == SDL_BUTTON_LEFT)
						this->inGame->gameGrid->play(PLAY_DIG, mouseXpos, mouseYpos, this->width, this->height);
					if (eventListener.button.button == SDL_BUTTON_RIGHT)
						this->inGame->gameGrid->play(PLAY_FLAG, mouseXpos, mouseYpos, this->width, this->height);
					this->inGame->gameGrid->update();

				}
				if (eventListener.button.button == SDL_BUTTON_LEFT) {
					this->btnFermer->btnClic_down(this->mouseXpos, this->mouseYpos);
				}
			}
		}
		//Relachement de clic
		if (eventListener.type == SDL_MOUSEBUTTONUP)
		{
			if (eventListener.button.button == SDL_BUTTON_LEFT) {
				SDL_GetMouseState(&this->mouseXpos, &this->mouseYpos);
				this->btnFermer->btnClic_up(this->mouseXpos, this->mouseYpos);
				this->act_fermer();
			}
		}
		if (eventListener.window.event == SDL_WINDOWEVENT_RESIZED)
		{
			SDL_GetWindowSize(this->mWindow, &this->width, &this->height);
			if(this->gameState == GAME_STATE_IN_GAME) this->inGame->gameGrid->update_Squares(this->width, this->height);
			this->mWallPaper->update(this->width, this->height);
			std::cout << "Change Size : (" << this->width << ";" << this->height << ")" << std::endl;
		}
	}
}

void Game::render()
{
	SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);

	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = this->width;
	rect.h = this->height;


	SDL_RenderFillRect(this->mRenderer, &rect);
	
	/*Affichage de fenetre en fonction de l'etat du JEU*/
	
	switch (this->gameState)
	{
	default:
		
		break;
	case GAME_STATE_MAIN_MENU:
		this->btnMenu->setPath("Ressources/Image/Default/Button_Default_Empty_Rest.png", "Ressources/Image/Default/Button_Default_Empty_Pressed.png");
		this->btnMenu->updateBtnTxt(this->width, this->height);
		this->btnMenu->draw();
		break;
	case GAME_STATE_IN_GAME :
		this->mWallPaper->draw();
		this->inGame->draw();
			

		//this->monText->draw();
		break;
	case GAME_STATE_SETTINGS:
		break;
	case GAME_STATE_GAME_OVER:
		break;
	}
	



	this->frameCount++;
	int timerFPS = SDL_GetTicks() - lastFrame;
	if (timerFPS < (1000/60))
	{
		SDL_Delay((1000 / 60) - timerFPS);
	}

	SDL_RenderPresent(mRenderer);
}

void Game::draw(Object obj)
{
	SDL_Rect dest = obj.get_dest();
	SDL_Rect src = obj.get_src();

	SDL_RenderCopy(this->mRenderer, obj.get_texture(), &src, &dest);
}



void Game::act_fermer() {
	if (this->btnFermer->get_action()) {
		this->isRunning = false;
		this->btnFermer->set_action(false);
	}
}