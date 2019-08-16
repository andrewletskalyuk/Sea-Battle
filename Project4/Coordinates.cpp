#include "Coordinates.h"


Coordinates::Coordinates()
{
}

Coordinates::Coordinates(int _x, int _y): x(_x), y(_y)
{
}

Coordinates::~Coordinates()
{
}

void Coordinates::setX(int _x)
{
	this->x = _x;
}

void Coordinates::setY(int _y)
{
	this->y = _y;
}

int Coordinates::getX() const 
{
	return this->x;
}

int Coordinates::getY() const 
{
	return this->y;
}
