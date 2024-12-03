#pragma once
#include <iostream>
#include "Position.h"
#include "StaticBoard.h"
#include "utils.h"

class MovingObj {
protected:
	StaticBoard& board;	// reference to board

	char icon;

	Position location;
	Position currentDir;

	void erase();
	void drawOldLoc();

	bool isFloor(char ch);
	bool isLadder(char ch);
	bool isBarrel(char ch);

	bool isPosOutOfBorder(Position pos);

	bool isOnFloor(Position pos);

public:
	MovingObj(StaticBoard& b, char i, Position loc, Position curr);
	void draw() {
		gotoxy(location.getX(), location.getY());
		std::cout << icon;
	}
};


