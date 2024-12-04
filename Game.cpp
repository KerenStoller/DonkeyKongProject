#include "Game.h"
#include <conio.h>
#include <windows.h>

void Game::start()
{

	ShowConsoleCursor(false);
	//get board from board
	board.printInit();

	int i = 0, j = 0;
	int barrelsCreated = 0;

	int frameCounterForShowing = 0;
	int barrelFr = 0;

	mario.draw(); // initial spot

	char key = 'e';	/////////////////////////////////////just for now
	while (key != 27) // esc
	{
		if (i < 5 and frameCounterForShowing % 4 == 0)
		{
			barrels[i]->draw();
			barrelsCreated++;
			i++;
		}
		frameCounterForShowing++;
		if (barrelFr % 2 == 0)
		{
			for (j = 0; j < barrelsCreated; j++)
			{

				barrels[j]->move();
			}
		}

		barrelFr++;

		Sleep(80);
		if (_kbhit()) {
			key = _getch();
			mario.changeDir(key);
		}
		else {
			mario.move();
		}


		if (hasWonOrLost())
		{
			key = 27;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		delete barrels[i];
	}
}


// function checks if mario won or lost
bool Game::hasWonOrLost()
{
	Position marioPos = mario.getLocation();
	if (marioPos == PaulineLoc)
	{
		won = true;
		return true;
	}
	if (marioPos == DonkeyKongLoc)
	{
		lives--;
		return true;
	}
	for (int i = 0; i < 5; i++)
	{
		if (marioPos == barrels[i]->getLocation())
		{
			lives--;
			return true;
		}
	}
	return false;
}