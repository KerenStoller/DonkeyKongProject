#include "Position.h"

constexpr int JUMP_LENGTH = 5;

struct Directions {
	Position LEFT;
	Position UP;
	Position RIGHT;
	Position DOWN;
	Position STAY;
};

const Directions directions = {
	//LEFT //UP	   //RIGHT//DOWN //STAY
	{-1,0}, {0,-1}, {1,0}, {0,1}, {0,0}
};

enum key {
	LEFT = 'a',
	UP = 'w',
	RIGHT = 'd',
	DOWN = 'x',
	STAY = 's'
};

enum floorDir {
	LEFT_FLOOR = '<',
	RIGHT_FLOOR = '>',
	SURPRISE_FLOOR = '='
};