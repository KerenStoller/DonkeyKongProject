#pragma once
#include "StaticBoard.h"
#include <iostream>

char StaticBoard::getChar(Position pos)
{
	return staticBoard[pos.getY()][pos.getX()];
}

void StaticBoard::printInit()
{
	//printing board
	for (int i = 0; i < MAX_Y - 1; i++) {
		std::cout << staticBoard[i] << '\n';
	}
	std::cout << staticBoard[MAX_Y - 1];
}
