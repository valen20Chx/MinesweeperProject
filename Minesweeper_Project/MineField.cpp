#include "MineField.h"

MineField::MineField(int width, int height, int percentBomb)
{
	srand(time(NULL));

	this->width = width;
	this->height = height;
	this->percentBomb = percentBomb;

	this->grid.resize(width);

	for (int i = 0; i < this->grid.size(); i++)
	{
		this->grid[i].resize(height);
	}
	
	this->nbBombs = (((width * height) * percentBomb) / 100);

	for (int ctor = 0; ctor < this->nbBombs; ctor++)
	{
		int correctPlacement = false;

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

void MineField::play(int playType, int x, int y)
{
	switch (playType)
	{
	case PLAY_DIG:
		this->grid[x][y].reveal();
		break;
	case PLAY_FLAG:
		this->grid[x][y].set_isFlagged(!this->grid[x][y].get_isFlagged());
		break;
	default:
		break;
	}
}