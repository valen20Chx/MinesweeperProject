#include "Game.h"

Game::Game(std::string title, int width, int height, bool fullScreen)
{
	this->gameState = GAME_STATE_MAIN_MENU;
	this->fullScreen = fullScreen;
	this->width = width;
	this->height = height;
	this->isRunning = true;
	this->mReseau = NULL;
	this->count = 0;
	this->frameCount = 0;
	this->lastFrame = 0;
	this->timerFPS = 0;
	
	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();

	SDL_CreateWindowAndRenderer(this->width, this->height, SDL_WINDOW_RESIZABLE, &this->mWindow, &this->mRenderer);

	SDL_SetWindowTitle(this->mWindow, this->title.c_str());

	this->gameScene = new MainMenu(this->mRenderer, 0, 0, this->width, this->height);
	
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
	//Listen

	SDL_Event* eventListener = new SDL_Event();
	while (SDL_PollEvent(eventListener))
	{
		this->gameScene->input(*eventListener);
		if (eventListener->type == SDL_QUIT)
		{
			this->isRunning = false;
		}
		if (eventListener->window.event == SDL_WINDOWEVENT_RESIZED)
		{
			SDL_GetWindowSize(this->mWindow, &this->width, &this->height);
			this->gameScene->windowSizeChanged(this->width, this->height);
			std::cout << "Change Size : (" << this->width << ";" << this->height << ")" << std::endl;
		}
	}

	//Handle

	switch(this->gameScene->get_action())
	{
		case ACTION_NONE:
		break;

		case ACTION_QUITTER:
		this->gameScene->set_action(ACTION_NONE);
		this->isRunning = false;
		break;

		case ACTION_TO_INGAME:
		this->gameScene->set_action(ACTION_NONE);
		this->gameScene->set_seed();
		std::cout << "creation scene In game";
		this->gameScene = new StateInGame(this->mRenderer, 0, 0, this->width, this->height, this->gameScene->get_mineSettings()); // TODO : test
		std::cout << "fin creation de scene IN GAME";
		break;

		case ACTION_TO_SETTINGS_GAME:
		this->gameScene->set_action(ACTION_NONE);
		this->gameScene = new SettingGame(this->mRenderer, 0, 0, this->width, this->height); 
		break;

		case ACTION_TO_MENU:
		this->gameScene->set_action(ACTION_NONE);
		this->gameScene = new MainMenu(this->mRenderer, 0, 0, this->width, this->height);
		this->gameState = GAME_STATE_MAIN_MENU;
		break;

		case ACTION_TO_SCOREBOARD:
		this->gameScene->set_action(ACTION_NONE);
		this->gameScene = new ScoreBoardScene(this->mRenderer, 0, 0, this->width, this->height, this->gameScene->get_gameResult());
		break;

		case ACTION_SET_HARD:
		this->gameScene->set_action(ACTION_NONE);
		this->gameScene->set_hard();
		break;

		case ACTION_SET_AVG:
			this->gameScene->set_action(ACTION_NONE);
			this->gameScene->set_average();
		break;

		case ACTION_SET_EASY:
			this->gameScene->set_action(ACTION_NONE);
			this->gameScene->set_easy();
		break;

		case ACTION_SET_LARGE:
			this->gameScene->set_action(ACTION_NONE);
			this->gameScene->set_large();
		break;

		case ACTION_SET_MED:
			this->gameScene->set_action(ACTION_NONE);
			this->gameScene->set_medium();
		break;

		case ACTION_SET_SMALL:
			this->gameScene->set_action(ACTION_NONE);
			this->gameScene->set_small();
		break;

		case ACTION_TO_CONNECTION:
			this->gameScene->set_action(ACTION_NONE);
			this->gameScene = new SceneConnect(this->mRenderer, 0, 0, this->width, this->height);
			TCPsocket newSocket;
			this->mReseau = new Reseau({127000000001,9999}, 9999); // TODO : Verifier
			break;
	}
}

void Game::render()
{
	//Clear Screen
	SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
	SDL_Rect rect;
	rect.x = 0;
	rect.y = 0;
	rect.w = this->width;
	rect.h = this->height;
	SDL_RenderFillRect(this->mRenderer, &rect);
	
	//Draw Scene
	this->gameScene->draw();

	//Update frameCount
	this->frameCount++;
	int timerFPS = SDL_GetTicks() - lastFrame;
	if (timerFPS < (1000/60))
	{
		SDL_Delay((1000 / 60) - timerFPS);
	}

	//Draw on window
	SDL_RenderPresent(mRenderer);
}