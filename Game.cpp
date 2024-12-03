#include "Game.h"
#include <conio.h>
#include <windows.h>

void Game::start()
{
	//get board from board
	board.printInit();

	mario.draw(); // initial spot

	char key = 'e';	/////////////////////////////////////just for now
	while (key != 27) // esc
	{
		/*
		for (int i = 0; i < 5; i++)
		{
			barrels[i]->draw();
		}
		*/

		Sleep(50);
		if (_kbhit())
		{
			key = _getch();
			if (mario.changeDir(key) == 1)
			{
				key = 27;
			}
		}
		else
		{
			if (mario.move() == 1)
			{
				key = 27;
			}
		}
	}

	for (int i = 0; i < 5; i++)
	{
		delete barrels[i];
	}
}