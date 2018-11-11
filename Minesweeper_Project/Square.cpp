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
		this->neighbourCounter = NEIGHBOUR_INIT_IS_BOMB;
	}
	else
	{
		this->neighbourCounter = NEIGHBOUR_INIT_IS_NOT_BOMB;
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
	if(!this->isFlagged) this->isHidden = false;
}

bool Square::get_isFlagged()
{ 
	return this->isFlagged;
}

void Square::set_isFlagged(bool isFlagged)
{
	this->isFlagged = isFlagged;
}