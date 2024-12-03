#include "Barrel.h"

void Barrel::Start()
{
	if (isFloor(board.getChar(location)))
	{
		// change dir according to floor
	}
	else if(location.getY() == board.MAX_Y)
	{
		// die
	}
	else
	{

		//continue falling
	}
}
