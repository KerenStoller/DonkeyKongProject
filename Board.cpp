#include "Board.h"

void Board::start()
{
	//printing board
	for (int i = 0; i < MAX_Y - 1; i++) {
		std::cout << originalBoard[i] << '\n';
	}
	std::cout << originalBoard[MAX_Y - 1];
	mario.draw();
	mario.move('d');
	mario.draw();
}