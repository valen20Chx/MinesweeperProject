#include "Game.h"

Game::Game(std::string title, int width, int height, bool fullScreen)
{
	this->gameState = GAME_STATE_SETTINGS;
	this->fullScreen = fullScreen;
	this->width = width;
	this->height = height;
	this->isRunning = true;

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
	SDL_Event* eventListener = new SDL_Event();
	while (SDL_PollEvent(eventListener))
	{
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

void Game::switchToMainMenu()
{
	this->gameScene = new MainMenu(this->mRenderer, 0, 0, this->width, this->height);
	this->gameState = GAME_STATE_MAIN_MENU;
}

void Game::quitGame()
{
	this->isRunning = false;
}