#include "Mario.h"

void Mario::move(char key)
{
	for (int i = 0; i < numKeys; i++)
	{
		if (std::tolower(key) == keys[i])
		{
			dir = directions[i];
			_x += dir.x;
			_y += dir.y;
			return;
		}
	}
	//else
}