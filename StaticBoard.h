#pragma once
#include "Position.h"

// will get from Game.cpp.

class StaticBoard {

public:

	char getChar(Position pos);
	void printInit();
	static constexpr int MAX_Y = 25;
	static constexpr int TOP_OF_BOARD = 0;
private:
	const char* staticBoard[MAX_Y] = {
		// 01234567890123456789012345678901234567890123456789012345678901234567890123456789
		  "                                                                                ", // 0
		  "                                                                                ", // 1
		  ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>     >>>>>>>>  >>>>>>>>>>>>>>>>>", // 2
		  "                                        H                H                      ", // 3
		  "                                        H                H                      ", // 4
		  "                 <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<                      ", // 5
		  "                 H         H      H                      H                      ", // 6
		  "                 H         H      H                      H                      ", // 7
		  "                 H         H      H                      H                      ", // 8
		  "                 H         H      H    >>>>>>>>>>>>>>>>>>>                      ", // 9
		  "                 H         H      H                                             ", // 10
		  "                 H         H      >>>>>>>>>>>>>>>>>>>>   >>>>>>>>>>>>>>>>>>>>>>>", // 11
		  "                 H         H                                                    ", // 12
		  "                 H         H                                                    ", // 13
		  "                 H         H      <<<<<<<<<<<<<<<<<       <<<<<<<<<<<<<<   <<<<<", // 14
		  ">>>>>>>>>>>>>>>>>>>>>>     H                                                    ", // 15
		  "                           H                                                    ", // 16
		  "                           H                                                    ", // 17
		  "                           H                                                    ", // 18
		  "                           H                                                    ", // 19
		  "                           H                                                    ", // 20
		  "         >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>", // 21
		  ">>>                        H        H                                           ", // 22
		  "                           H        H                                           ", // 23
		  "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"  // 24
	};

};