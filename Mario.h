#pragma once
#include <iostream>
#include "utils.h"

class Mario {
	int _x = 1, _y = 23; // initial position
	struct Direction { int x, y; };
	Direction dir = { 0,0 };
	char me = '@';
	static constexpr char keys[] = { 'a', 'w', 'd', 'x', 's' };
	static constexpr int numKeys = sizeof(keys) / sizeof(char);
	static constexpr Direction directions[] = { {-1,0}, {0,-1}, {1,0}, {0,1}, {0,0} };
	void erase();

public:
	void draw()
	{
		gotoxy(_x, _y);
		std::cout << me;
	}
	void move(char key);
};