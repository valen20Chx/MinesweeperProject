#include <iostream>

#include "MineField.h"

int main(void)
{
	MineField field(20, 20, 15);

	field.printStats();

	field.draw_gridASCII();

	field.play(PLAY_DIG, 5, 7);
	field.play(PLAY_DIG, 8, 9);
	field.play(PLAY_DIG, 3, 15);
	field.play(PLAY_DIG, 13, 10);

	field.draw_gridASCII();
	
	system("pause");

	return 0;
}