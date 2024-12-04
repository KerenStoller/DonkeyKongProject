#pragma once
#include "MovingObj.h"
#include "StaticBoard.h"

class Barrel : public MovingObj
{
public:
	Barrel(StaticBoard& b) : MovingObj(b, 'O', { 2,0 }, { 0,0 }, {0,0}) {};
	void move();
	void changeDir();
};