#pragma once
#include <iostream>
#include "Mario.h"
#include "StaticBoard.h"
#include "Barrel.h"

/*
this class gets keys from Game and sends them to mario to move.
Class keeps track of location of all objects (gets initial location from StaticObj).
Class is parent to StaticObj + Mario --> Mario knows if he is on the floor etc...
as soon as Mario touches a barrel -> class will ?? 
*/

class Game {

	Mario mario;
	StaticBoard board;
	Barrel* barrels[5];

public:
	Game() : mario(board) {
		barrels[0] = new Barrel(board);
		barrels[1] = new Barrel(board);
		barrels[2] = new Barrel(board);
		barrels[3] = new Barrel(board);
		barrels[4] = new Barrel(board);
	};
	void start();
};