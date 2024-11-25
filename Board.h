#pragma once
#include <iostream>
#include "Mario.h"


/*
this class gets keys from Game and sends them to mario to move.
Class keeps track of location of all objects (gets initial location from StaticObj).
Class is parent to StaticObj + Mario --> Mario knows if he is on the floor etc...
as soon as Mario touches a barrel -> class will ?? 
*/

class Board {
	static constexpr int MAX_X = 80;
	static constexpr int MAX_Y = 25;

	//getting this from StaticObj!
	const char* originalBoard[MAX_Y] = {
		// 01234567890123456789012345678901234567890123456789012345678901234567890123456789
		  "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW", // 0
		  "W                                                                              W", // 1
		  "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW     WWWWWWWW  WWWWWWWWWWWWWWWWW", // 2
		  "W                                       W                W                     W", // 3
		  "W                                       W                W                     W", // 4
		  "W                WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW                     W", // 5
		  "W                W                WW     W               W                     W", // 6
		  "W                W                WW     W  WWWW         W                     W", // 7
		  "W                W                WW          WW                               W", // 8
		  "W                W         W      WW   WWWWWWWWWWWWWWWWWWW                     W", // 9
		  "W                W         W      WW                     W                     W", // 10
		  "W                W         W      WWWWWWWWWWWWWWWWWWWW   WWWWWWWWWWWWWWWWWWWWWWW", // 11
		  "W                W         W      WW                 W                         W", // 12
		  "W                   W      W                         WWWWWW                    W", // 13
		  "W                   W      W      WWWWWWWWWWWWWWWWW       WWWWWWWWWWWWWW   WWWWW", // 14
		  "WWWWWWWWWWWWWWWWWWWWW      W      WW                               W   W       W", // 15
		  "W        W          W      W      WW                               W   W       W", // 16
		  "W        W                 W      WW                               W   WWW  WWWW", // 17
		  "W        W    WWWWWWWWWWWWWWWW                                     W   W       W", // 18
		  "W                 W        W      WW                               W   W       W", // 19
		  "W                 W        W      WW                                   WWWWWW  W", // 20
		  "W         END     W               WW                                   W       W", // 21
		  "W                 W               WW                               W           W", // 22
		  "W                 W               WW                               W   W       W", // 23
		  "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"  // 24
	};

	Mario mario;

	void move(char key)
	{
		mario.move(key);
	}

public:
	void start();
};