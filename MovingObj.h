#pragma once
#include <iostream>
#include "Position.h"
#include "StaticBoard.h"
#include "Directions.h"
#include "utils.h"

enum GravityState
{
	ON_GROUND,     // Mario is on the ground
	JUMPING,       // Mario is going upwards (jumping)
	FALLING,       // Mario is falling after a jump
	FREE_FALLING,  // Mario is free falling (no horizontal control, gravity pulling down)
	ON_LADDER      // Mario is climbing or standing on a ladder
};

static const int JUMP_HEIGHT = 2;

class MovingObj {
protected:
	StaticBoard& board;	// reference to board

	char icon;

	Position location;
	
	Position xAxisDir;
	Position yAxisDir;

	GravityState gravityState = FALLING;

	void erase();
	void drawOldLoc();

	bool isFloor(char ch);
	bool isLadder(char ch);

	bool isOnFloor(Position pos);
	bool isPosOutOfBorder(Position pos);

	void manageGravity();

public:
	MovingObj(StaticBoard& _b, char _i, Position _loc, Position _xDir, Position _yDir);
	void draw() {
		gotoxy(location.getX(), location.getY());
		std::cout << icon;
	}
	Position getLocation();
};


