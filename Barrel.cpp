#include "Barrel.h"

void Barrel::move()
{
	manageGravity();

	if (gravityState == ON_GROUND)
	{
		changeDir();
	}

	Position newPos = location + xAxisDir + yAxisDir;
	if (isPosOutOfBorder(newPos)) {
		//prevent further movement
		yAxisDir = directions.STAY;
		xAxisDir = directions.STAY;
	}
	else
	{
		// Erase old location and move to new position
		erase();
		drawOldLoc();
		location = newPos;
		draw();
	}
	return;
}

void Barrel::changeDir()
{	// mario is on the floor (gravity state is ON_GROUND)
	yAxisDir = directions.STAY;

	char floorTile = board.getChar(Position(location.getX(), location.getY() + 1));
	switch (floorTile)
	{
	case LEFT_FLOOR:
		xAxisDir = directions.LEFT;
		break;
	case RIGHT_FLOOR:
		xAxisDir = directions.RIGHT;
		break;
	case SURPRISE_FLOOR:
		xAxisDir = directions.LEFT;
		break;
	}
}