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