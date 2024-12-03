#pragma once

class Position
{
	int x, y;

public:
	Position() : x(0), y(0) {};
	Position(int _x, int _y) : x(_x), y(_y) {}
	int getX() { return x; };
	void setX(int newX) { x = newX; };
	int getY() { return y; };
	void setY(int newY) { y = newY; };
	void setXY(int newX, int newY) { x = newX; y = newY; };

	bool operator==(Position pos2) {
		return (x == pos2.x and y == pos2.y);
	}
	bool operator!=(Position pos2) {
		return (x != pos2.x or y != pos2.y);
	}
};