#pragma once

#define NEIGHBOUR_INIT_IS_BOMB -1;
#define NEIGHBOUR_INIT_IS_NOT_BOMB 0;

class Square
{
private:
	int neighbourCounter;
	bool isBomb;
	bool isHidden;
	bool isFlagged;
public:
	Square();
	Square(bool isBomb);
	~Square();
	void set_neibourCounter(int neibourCounter);
	void set_isBomb(bool isBomb);
	void set_isFlagged(bool isFlagged);
	int get_neibourCounter();
	bool get_isBomb();
	bool get_isHidden();
	bool get_isFlagged();
	void reveal();
};

