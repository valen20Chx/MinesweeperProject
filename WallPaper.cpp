#include "WallPaper.h"

WallPaper::WallPaper(int imgWidth, int imgHeight, int screenWidth, int screenHeight, std::string path, SDL_Renderer* wRenderer)
{
	this->imgWidth = imgWidth;
	this->imgHeight = imgHeight;
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	this->path = path;
	this->wRenderer = wRenderer;

	this->mSurface = IMG_Load(this->path.c_str());
	if (this->mSurface == NULL)
		std::cout << "Error : Could not render surface from : " << this->path << std::endl;
	this->mTexture = SDL_CreateTextureFromSurface(this->wRenderer, this->mSurface);
	if (this->mTexture == NULL)
		std::cout << "Error : Could not Create Texture from surface" << std::endl;
}

WallPaper::~WallPaper()
{
	SDL_DestroyTexture(this->mTexture);
	SDL_FreeSurface(this->mSurface);
}

void WallPaper::draw()
{
	//std::cout << "Test draw wallpaper" << std::endl;
	SDL_Rect dest;
	SDL_Rect src;

	src.x = 0;
	src.y = 0;
	src.w = this->imgWidth;
	src.h = this->imgHeight;

	dest.w = src.w;
	dest.h = src.h;

	for (int i = 0; i < (screenWidth / src.w) + 1; i++)
	{
		for (int j = 0; j < (screenHeight / src.h) + 1; j++)
		{
			dest.x = i * src.w;
			dest.y = j * src.h;

			SDL_RenderCopy(this->wRenderer, this->mTexture, &src, &dest);
		}
	}

}

void WallPaper::setImage(std::string path)
{
	this->mSurface = IMG_Load(this->path.c_str());
	this->mTexture = SDL_CreateTextureFromSurface(wRenderer, this->mSurface);
}

void WallPaper::update(int screenWidth, int screenHeight)
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
}