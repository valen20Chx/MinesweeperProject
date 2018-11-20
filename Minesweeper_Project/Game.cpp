#include "Game.h"

Game::Game(std::string title, int width, int height, bool fullScreen)
{
	this->fullScreen = fullScreen;
	this->width = width;
	this->height = height;
	this->isRunning = true;

	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	SDL_CreateWindowAndRenderer(this->width, this->height, NULL, &this->mWindow, &this->mRenderer);

	SDL_SetWindowTitle(this->mWindow, this->title.c_str());

	star.set_dest(50, 50, 32, 32);
	star.set_dest(0, 0, 16, 16);
	star.setImage("Ressources/book.png", this->mRenderer);

	loop();
}

Game::~Game()
{
	SDL_DestroyRenderer(this->mRenderer);
	SDL_DestroyWindow(this->mWindow);

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
			frameCount = 0;
			this->count++;
		}

		this->render();
		this->input();
		this->update();

		if (this->count > 3)
		{
			isRunning = false;
		}
	}
}

void Game::update()
{

}

void Game::input()
{

}

void Game::render()
{
	SDL_GetRenderDrawColor(mRenderer, 0, 0, 0, 0);

	SDL_Rect rect;

	rect.x = 0;
	rect.y = 0;
	rect.w = this->width;
	rect.h = this->height;

	SDL_RenderFillRect(this->mRenderer, &rect);

	draw(star);

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

	SDL_RenderCopyEx(this->mRenderer, obj.get_texture(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
}