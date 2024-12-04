#pragma once
#include <iostream>
#include "utils.h"
#include "Position.h"
#include "MovingObj.h"


#define INITIALPOS = {1,23}

class Mario : public MovingObj{

	int jumpCounter = 0;

	void moveUp(Position& newPos);
	void moveDown(Position& newPos);

public:
	// MAGIC NUMBERS!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	Mario(StaticBoard& b) : MovingObj(b, '@', Position{1,23},  directions.STAY, directions.STAY) {};
	void changeDir(char key);
	void move();
};