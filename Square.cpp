#include "Square.h"

Square::Square()
{
	this->isBomb = false;
	this->isHidden = true;
	this->neighbourCounter = NEIGHBOUR_INIT_IS_NOT_BOMB;
	this->isFlagged = false;
}

Square::Square(bool isBomb)
{
	this->isBomb = isBomb;
	this->isHidden = true;
	this->isFlagged = false;
	if (isBomb)
	{
		this->neighbourCounter = NEIGHBOUR_INIT_IS_BOMB;  //on affichera pas le nombre
	}
	else
	{
		this->neighbourCounter = NEIGHBOUR_INIT_IS_NOT_BOMB; //on affichera le nombre
	}
}

Square::~Square()
{
}

void Square::set_neibourCounter(int neibourCounter)
{
	this->neighbourCounter = neibourCounter;
}

void Square::set_isBomb(bool isBomb)
{
	this->isBomb = isBomb;
}

int Square::get_neibourCounter()
{
	return this->neighbourCounter;
}

bool Square::get_isBomb()
{
	return this->isBomb;
}

bool Square::get_isHidden()
{
	return this->isHidden;
}

void Square::reveal()
{
	if (!this->isFlagged)
	{
		this->isHidden = false;
		if (this->get_isBomb())
		{
			this->set_src(32, 0, 16, 16); //chagment position x image source
		}
		else
		{
			this->set_src(48 + (this->get_neibourCounter() * 16), 0, 16, 16); //de la case 0 a 8 de l'image source
		}
	}
}

bool Square::get_isFlagged()
{
	return this->isFlagged;
}

void Square::set_isFlagged(bool isFlagged)
{
	this->isFlagged = isFlagged;
	if (this->isFlagged)
	{
		this->set_src(0, 0, 16, 16);
	}
	else
	{
		this->set_src(16, 0, 16, 16);
	}
}