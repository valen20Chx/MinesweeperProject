#include "MineField.h"

MineField::MineField(int width, int height, int percentBomb, unsigned int seed)
{
	this->width = width;
	this->height = height;
	this->percentBomb = percentBomb;
	this->seed = seed;

	this->grid.resize(width);

	for (int i = 0; i < (this->grid.size()); i++)
	{
		this->grid[i].resize(height);
	}

	this->nbBombs = (((width * height) * percentBomb) / 100);

	srand(this->seed);

	for (int ctor = 0; ctor < this->nbBombs; ctor++) // place les bombes aleatoirement si la case n'est pas une bombe
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

	for (int j = 0; j < this->height; j++) //compte les bombes voisine pour chaque case
	{
		for (int i = 0; i < this->width; i++)
		{
			if (!this->grid[i][j].get_isBomb())
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

				if (j != 0)
					if (this->grid[i][j - 1].get_isBomb()) nbB++;

				if (j != (height - 1))
					if (this->grid[i][j + 1].get_isBomb()) nbB++;

				this->grid[i][j].set_neibourCounter(nbB); //pour chaque case on donne le nombre de voisin compté avant
			}
		}
	}
}


//afficher que des cases cachée

/*	
Minefield::drawBlocks(int x, int y, int xMax, int yMax)
{
	this->grid[x][y].set_src(16, 0, 16, 16); //normalement je parcour chaque "square" du "grid" de ce MineField
	this->grid[x][y].setImage("Ressources/Image/Default/Sprite_Default.png", this->mRenderer);

	
		if (x + 1 <= xMax) { //si on est pas a la derniere collone
			this->grid[x][y].set_dest(16 * x, 16 * y, 16, 16);  //x celon le nombre en collone et y en ligne
			drawBlocks(x + 1, y, xMax, yMax, OBJ),
		}
		else if(y + 1 <= yMax) { //sinon on passe a la premiere collonne et prochaine ligne si il y a
			this->grid[x][y].set_dest(16 * x, 16 * y, 16, 16);  
			drawBlocks( 0, y + 1, xMax, yMax, OBJ),
		}
		// si plus de ligne apres c'est fini
		

	SDL_RenderCopyEx(this->mRenderer, obj.get_texture(), &src, &dest, 0, NULL, SDL_FLIP_NONE);
}

	*/



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

void MineField::set_Squares(int screenWidth, int screenHeight, SDL_Renderer* screenRenderer)
{
	for (int i = 0; i < this->width; i++)
	{
		for (int j = 0; j < this->height; j++)
		{
			int destX = (20 + (i * (screenWidth / this->width))); //20 =  espace coté
			int destY = (30 + (j * (screenHeight / this->height)));; //30 espace haut
			int destW = ((screenWidth / this->width) - 40);
			int destH = ((screenHeight / this->height) - 50);;

			this->grid[i][j].set_src(16, 0, 16, 16);
			this->grid[i][j].set_dest(destX, destY, destW, destH);
			this->grid[i][j].setImage("Ressources/Image/Default/Sprite_Default.png", screenRenderer);
			//std::cout << "test";
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