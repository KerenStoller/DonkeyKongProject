#include "Mario.h"

/*
function assigns pressed key to new direction
*/
void Mario::changeDir(char keyPressed)
{
	switch (std::tolower(keyPressed))
	{
	case(LEFT):
		xAxisDir = directions.LEFT;
		break;
	case(RIGHT):
		xAxisDir = directions.RIGHT;
		break;
	case(UP):
		yAxisDir = directions.UP;
		break;
	case(DOWN):
		yAxisDir = directions.DOWN;
		break;
	case(STAY):
		yAxisDir = directions.STAY;
		xAxisDir = directions.STAY;
		break;
	default: //ignore
		break;
	}

	move();
}


/*
function takes care of up movement: 
	1) ladder
	2) jumping
*/
void Mario::moveUp(Position& newPos)
{
	// start of ladder
	if (isLadder(board.getChar(newPos)) and isOnFloor(location)) {
		gravityState = ON_LADDER;
	}
	// end of ladder (when reaching floor)
	else if (gravityState == ON_LADDER and isFloor(board.getChar(newPos))) {
		newPos.setY(newPos.getY() - 1);	// skip floor
		gravityState = ON_GROUND;
		yAxisDir = directions.STAY;
	}
	// jump
	else if(gravityState != ON_LADDER) {
		// if mario touches floor
		if (isFloor(board.getChar(newPos))) {
			gravityState = FALLING;
			newPos.setY(newPos.getY() + 1);	//undo jump
			yAxisDir = directions.DOWN;
			return;
		}

		// start of jump
		if (gravityState == ON_GROUND) {
			gravityState = JUMPING;
			jumpCounter = 0;
		}
		jumpCounter++;
		if (jumpCounter == JUMP_HEIGHT)	// end of jump
		{
			gravityState = FALLING;
		}
	}
}

/*
function takes care of moving down:
	1) falling
	2) climbing down the ladder
*/
void Mario::moveDown(Position& newPos)
{	
	if (gravityState == FREE_FALLING or gravityState == FALLING) { return; }

	// start of ladder
	if (gravityState != ON_LADDER) {	
		newPos.setY(newPos.getY() + 1); //check under floor
		if (isPosOutOfBorder(newPos) or !isLadder(board.getChar(newPos))) {
			newPos.setY(newPos.getY() - 2);	// correct position if out of bounds
			yAxisDir = directions.STAY;
		} 
		else {
			gravityState = ON_LADDER;
		}
	}
	// end of ladder (mario reaches the floor)
	else if (gravityState == ON_LADDER and isOnFloor(location)) {
		gravityState = ON_GROUND;
		newPos.setY(newPos.getY() - 1);	// change newPos back to floor
		yAxisDir = directions.STAY;
	}
}


/*
function moves mario to new location only if location is valid
*/
void Mario::move()
{
	manageGravity();

	if (yAxisDir == directions.STAY and xAxisDir == directions.STAY) { return; } // nothing to do

	Position newPos = location + xAxisDir + yAxisDir;

	if (isPosOutOfBorder(newPos)) {
		//prevent further movement
		if (gravityState == ON_GROUND)
		{
			xAxisDir = directions.STAY;
		}
		yAxisDir = directions.STAY;
		gravityState = FALLING;
	}
	else
	{
		if (yAxisDir == directions.UP) {
			moveUp(newPos);
		}
		else if (yAxisDir == directions.DOWN) {
			moveDown(newPos);
		}

		// Erase old location and move to new position
		erase();
		drawOldLoc();
		location = newPos;
		draw();
	}

	return;
}