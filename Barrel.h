#pragma once
#include "MovingObj.h"
#include "StaticBoard.h"

class Barrel : public MovingObj
{
	void Start();
public:
	Barrel(StaticBoard& b) : MovingObj(b, 'B', { 0,0 }, { 0,1 }) {};
};