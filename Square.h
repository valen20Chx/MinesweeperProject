#pragma once

#include "Object.h"

#define NEIGHBOUR_INIT_IS_BOMB -1;
#define NEIGHBOUR_INIT_IS_NOT_BOMB 0;

class Square : public Object
{
private:
	int neighbourCounter; //le nombre de bombe autour de cette case
	bool isBomb;
	bool isHidden;
	bool isFlagged;
public:
	Square();
	Square(bool isBomb);
	~Square();
	void set_neibourCounter(int neibourCounter);//indiquer le nombre de bombe qu'il y a autour de chaque case (apres avoir compter)
	void set_isBomb(bool isBomb);					/// Pour nous permettre definir si c'est ou pas , l'ors de creation de partie
	void set_isFlagged(bool isFlagged);				///
	int get_neibourCounter();//obtenir le nombre de bombe qu'il y a autour de chaque case
	bool get_isBomb();								///
	bool get_isHidden();							///Pour l'ors du jeu savoir si il l'est ou pas
	bool get_isFlagged();							///
	void reveal(); //afficher le case invisible
};

