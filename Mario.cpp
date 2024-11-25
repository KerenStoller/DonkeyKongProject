#include "Mario.h"

void Mario::erase()
{
	gotoxy(_x, _y);
	std::cout << ' ';
}

void Mario::move(char key)
{
	for (int i = 0; i < numKeys; i++)
	{
		if (std::tolower(key) == keys[i])
		{
			erase(); // erase old location -> changing my location
			dir = directions[i];
			_x += dir.x;
			_y += dir.y;
			return;
		}
	}
	//else
}