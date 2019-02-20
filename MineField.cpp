#include "MineField.h"

MineField::MineField(int width, int height, int percentBomb, unsigned int seed)
{
	this->width = width;
	this->height = height;
	this->percentBomb = percentBomb;
	this->seed = seed;

	this->grid.resize(width);

	for (int i = 0; i < this->grid.size(); i++)
	{
		this->grid[i].resize(height);
	}
	
	this->nbBombs = (((width * height) * percentBomb) / 100);

	srand(this->seed);

	for (int ctor = 0; ctor < this->nbBombs; ctor++)
	{
		bool correctPlacement = false;

		while (!correctPlacement)
		{
			int tempX, tempY;
			tempX = rand() % width;
			tempY = rand() % height;

			if (!this->grid[tempX][tempY].get_isBomb())
			{
				correctPlacement = true;

				this->grid[tempX][tempY] = new Square(true);
			}
		}
	}

	for (int j = 0; j < this->height; j++)
	{
		for (int i = 0; i < this->width; i++)
		{
			if(!this->grid[i][j].get_isBomb())
			{
				int nbB = 0;
				if (i != 0)
				{
					if (j != 0)
					{
						if (this->grid[i - 1][j - 1].get_isBomb()) nbB++;
					}

					if (j != (height - 1))
					{
						if (this->grid[i - 1][j + 1].get_isBomb()) nbB++;
					}

					if (this->grid[i - 1][j].get_isBomb()) nbB++;
				}

				if (i != (width - 1))
				{
					if (j != 0)
					{
						if (this->grid[i + 1][j - 1].get_isBomb()) nbB++;
					}

					if (j != (height - 1))
					{
						if (this->grid[i + 1][j + 1].get_isBomb()) nbB++;
					}

					if (this->grid[i + 1][j].get_isBomb()) nbB++;
				}

				if(j != 0)
					if (this->grid[i][j - 1].get_isBomb()) nbB++;

				if(j != (height - 1))
					if (this->grid[i][j + 1].get_isBomb()) nbB++;

				this->grid[i][j].set_neibourCounter(nbB);
			}
		}
	}
	this->state = MF_STATE_STARTED;
	this->startTime = SDL_GetTicks();
}


MineField::~MineField()
{
}

int MineField::get_width()
{
	return this->width;
}

int MineField::get_height()
{
	return this->height;
}

int MineField::get_percentBomb()
{
	return this->percentBomb;
}

std::vector<std::vector<Square>> MineField::get_grid()
{
	return this->grid;
}

Square MineField::get_square(int x, int y)
{
	return this->grid[x][y];
}

void MineField::draw_gridASCII()
{
	int i;
	std::cout << std::endl << std::endl;

	for (i = 0; i < this->width; i++)
	{
		std::cout << i << " ";
	}

	std::cout << std::endl;

	for (int j = 0; j < this->height; j++)
	{
		std::cout << j << "  ";

		for (int i = 0; i < this->width; i++)
		{

			if (this->grid[i][j].get_isHidden())
			{
				if (this->grid[i][j].get_isFlagged())
				{
					std::cout << "F ";
				}
				else
				{
					std::cout << ". ";
				}
			}
			else if (this->grid[i][j].get_isBomb())
			{
				std::cout << "X ";
			}
			else
			{
				std::cout << this->grid[i][j].get_neibourCounter() << " ";
			}
		}
		std::cout << std::endl;
	}
}

void MineField::printStats()
{
	std::cout << "Width : " << this->width << std::endl;
	std::cout << "Height : " << this->height << std::endl;
	std::cout << "Percentage : " << this->percentBomb << std::endl;
}

void MineField::play(int playType, int x, int y, int screenWidth, int screenHeight)
{
	// Si dans zone de jeu
	if (x > GAME_MARGIN_LEFT && x < (screenWidth - (GAME_MARGIN_LEFT + GAME_MARGIN_RIGHT)) && y > GAME_MARGIN_TOP && y < (screenHeight - (GAME_MARGIN_TOP + GAME_MARGIN_BOTTOM)))
	{
		int xGrid = ((x - (GAME_MARGIN_LEFT + GAME_MARGIN_RIGHT)) * this->width) / (screenWidth - (GAME_MARGIN_LEFT + GAME_MARGIN_RIGHT));
		int yGrid = ((y - (GAME_MARGIN_TOP + GAME_MARGIN_BOTTOM)) * this->height) / (screenHeight - (GAME_MARGIN_TOP + GAME_MARGIN_BOTTOM));
		switch (playType)
		{
		case PLAY_DIG:
			this->grid[xGrid][yGrid].reveal();
			break;
		case PLAY_FLAG:
			this->grid[xGrid][yGrid].set_isFlagged(!this->grid[xGrid][yGrid].get_isFlagged());
			break;
		default:
			break;
		}
	}
}

void MineField::play_reveal(int x, int y)
{
	if (this->grid[x][y].get_isHidden() && !this->grid[x][y].get_isFlagged())
	{
		std::cout << "play_reveal called for : (" << x << ";" << y << ")" << std::endl;
		if (this->grid[x][y].get_isBomb())
		{
			this->grid[x][y].reveal();
			//Lose
			this->state = MF_STATE_LOSS;
			this->endTime = SDL_GetTicks();
		}
		else
		{
			this->grid[x][y].reveal();
			if (this->grid[x][y].get_neibourCounter() == 0)
			{
				if (x > 0)
				{
					this->play_reveal(x - 1, y);
					if (y > 0)
					{
						this->play_reveal(x - 1, y - 1);
					}
					if (y < (this->height - 1))
					{
						this->play_reveal(x - 1, y + 1);
					}
				}
				if (x < (this->width - 1))
				{
					this->play_reveal(x + 1, y);
					if (y > 0)
					{
						this->play_reveal(x + 1, y - 1);
					}
					if (y < (this->height - 1))
					{
						this->play_reveal(x + 1, y + 1);
					}
				}
				if (y > 0)
				{
					this->play_reveal(x, y - 1);
				}
				if (y < (this->height - 1))
				{
					this->play_reveal(x, y + 1);
				}
			}
		}
	}
}

void MineField::set_Squares(int screenWidth, int screenHeight, SDL_Renderer* screenRenderer)
{
	for (int i = 0; i < this->width; i++)
	{
		for (int j = 0; j < this->height; j++)
		{
			int destW = ((screenWidth- (GAME_MARGIN_LEFT + GAME_MARGIN_RIGHT)) / this->width);
			int destH = ((screenHeight - (GAME_MARGIN_TOP + GAME_MARGIN_BOTTOM)) / this->height);
			int destX = (GAME_MARGIN_LEFT + (i * destW));
			int destY = (GAME_MARGIN_TOP + (j * destH));

			this->grid[i][j].set_src(16, 0, 16, 16);
			this->grid[i][j].set_dest(destX, destY, destW, destH);
			this->grid[i][j].setImage("Ressources/Image/Default/Sprite_Default.png", screenRenderer);
		}
	}
}

void MineField::update_Squares(int screenWidth, int screenHeight)
{
	for (int i = 0; i < this->width; i++)
	{
		for (int j = 0; j < this->height; j++)
		{
			int destW = ((screenWidth - (GAME_MARGIN_LEFT + GAME_MARGIN_RIGHT)) / this->width);
			int destH = ((screenHeight - (GAME_MARGIN_TOP + GAME_MARGIN_BOTTOM)) / this->height);
			int destX = (GAME_MARGIN_LEFT + (i * destW));
			int destY = (GAME_MARGIN_TOP + (j * destH));
			this->grid[i][j].set_dest(destX, destY, destW, destH);
		}
	}
}

void MineField::draw(SDL_Renderer* renderer)
{
	for (int i = 0; i < this->width; i++)
	{
		for (int j = 0; j < this->height; j++)
		{
			SDL_Rect dest = this->grid[i][j].get_dest();
			SDL_Rect src = this->grid[i][j].get_src();

			SDL_RenderCopyEx(renderer, this->grid[i][j].get_texture(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
		}
	}
}

void MineField::update()
{
	bool allBombsFlag = true;
	for (int i = 0; i < this->nbBombs; i++)
	{
		if (!this->grid[bombsPos[i].x][bombsPos[i].y].get_isFlagged())
			allBombsFlag = false;
	}
	if (allBombsFlag)
	{
		unsigned int time = this->getRuningTicks();
		std::cout << "Won by finding all the Bombs in " << time << " ms" << std::endl;
		this->state = MF_STATE_WON;
		this->endTime = SDL_GetTicks();
	}
}

// Return numbers of miliseconds since start of MineField
unsigned MineField::getRuningTicks()
{
	if (this->state != MF_STATE_LOSS && this->state != MF_STATE_WON)
	{
		return (SDL_GetTicks() - this->startTime);
	}
	else
	{
		return (this->endTime - startTime);
	}
}