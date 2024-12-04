#include "MovingObj.h"

void MovingObj::erase()
{
	gotoxy(location.getX(), location.getY());
	std::cout << ' ';
}

void MovingObj::drawOldLoc()
{
	gotoxy(location.getX(), location.getY());
	std::cout << board.getChar(location);
}

bool MovingObj::isFloor(char ch)
{
	return (ch == '=' or ch == '<' or ch == '>');
}

bool MovingObj::isLadder(char ch)
{
	return (ch == 'H');
}

MovingObj::MovingObj(StaticBoard& _b, char _i, Position _loc, Position _xDir, Position _yDir) :
	board(_b), icon(_i), location(_loc), xAxisDir(_xDir), yAxisDir(_yDir)
{}

Position MovingObj::getLocation()
{
	return Position(location.getX(), location.getY());
}

bool MovingObj::isPosOutOfBorder(Position pos)
{
	return (pos.getX() < 0 or pos.getX() > 79 or pos.getY() > 24 or pos.getY() < 0);
}

bool MovingObj::isOnFloor(Position pos)
{
	pos.setXY(pos.getX(), pos.getY() + 1);	// check under
	if (isPosOutOfBorder(pos))
	{
		return false;
	}
	return(isFloor(board.getChar(pos)));
}

/*
function makes sure gravityState is up to date with yAxisDir
	plus, function disables horizantal movements in ON_LADDER and FREE_FALLING states
*/
void MovingObj::manageGravity()
{
	// falling after jump
	if (!isOnFloor(location) and gravityState == FALLING) {
		yAxisDir = directions.DOWN;
	}
	// dont allow lateral movement if mario is on ladder
	else if (!isOnFloor(location) and gravityState == ON_LADDER) {
		xAxisDir = directions.STAY;
	}
	// free falling 
	else if (!isOnFloor(location) and gravityState != JUMPING and gravityState != FALLING) {
		gravityState = FREE_FALLING;
		yAxisDir = directions.DOWN;
		xAxisDir = directions.STAY;			// no lateral movement
	}
	// stop falling once touching ground
	else if (isOnFloor(location) and gravityState != ON_GROUND and gravityState != ON_LADDER) {
		yAxisDir = directions.STAY;
		gravityState = ON_GROUND;
	}
}