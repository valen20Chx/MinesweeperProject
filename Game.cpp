#include "Game.h"

Game::Game(std::string title, int width, int height, bool fullScreen)
{
	this->fullScreen = fullScreen;
	this->width = width;
	this->height = height;
	this->isRunning = true;

	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	SDL_CreateWindowAndRenderer(this->width, this->height, SDL_WINDOW_RESIZABLE, &this->mWindow, &this->mRenderer);

	SDL_SetWindowTitle(this->mWindow, this->title.c_str());

	//this->star.set_src(0, 0, 16, 16);
	//this->star.set_dest(50, 50, 200, 200);
	//this->star.setImage("Ressources/Image/book.png", this->mRenderer);
	
	this->gameGrid = new MineField(10, 10, 5, 3);
	this->gameGrid->set_Squares(this->width, this->height, this->mRenderer);


	this->mWallPaper = new WallPaper(32, 32, this->width, this->height, "Ressources/Image/Default/Background_Repeat_01.png", this->mRenderer);

	this->monText = new Text(this->mRenderer, 100, 10, 20, 255000000, "Ressources/Font/OpenSans-Bold.ttf","test lessage");

	this->loop();
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
		if(eventListener.type == SDL_MOUSEBUTTONDOWN)
		{
			SDL_GetMouseState(&this->mouseXpos, &this->mouseYpos);
			if(eventListener.button.button == SDL_BUTTON_LEFT)
				this->gameGrid->play(PLAY_DIG, mouseXpos, mouseYpos, this->width, this->height);
			if(eventListener.button.button == SDL_BUTTON_RIGHT)
				this->gameGrid->play(PLAY_FLAG, mouseXpos, mouseYpos, this->width, this->height);
		}
		if(eventListener.window.event == SDL_WINDOWEVENT_RESIZED)
		{
			SDL_GetWindowSize(this->mWindow, &this->width, &this->height);
			this->gameGrid->update_Squares(this->width, this->height);
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

	//this->draw(star);
	this->monText->draw();

	this->mWallPaper->draw();
	this->drawMinefield();

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

void Game::drawMinefield()
{
	this->gameGrid->draw(this->mRenderer);
}