#pragma once
#include <iostream>
#include "Mario.h"

class GameObj {
	static const int MAX_X = 80;
	static const int MAX_Y = 25;

	enum Keys { MARIOS = 'd' };

	Mario mario;

	void move(Keys key)
	{
		mario.move(key);
	}

public:
	void start()
	{
		mario.draw();
		mario.move('d');
		mario.draw();
	}

};