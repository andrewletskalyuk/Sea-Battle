#include "Ship.h"
#include <vector>

Ship::Ship()
{
}

Ship::Ship(int _count_palubes)
{
	count_palubes = _count_palubes;
	for (int i = 0; i < count_palubes; i++)
	{
		LivePalubs.push_back(true);
	}
}

Ship::Ship(Coordinates _coordinates, Direction _direction, int _count_palubes)
{
	coordinates = _coordinates;
	direction = _direction;
	count_palubes = _count_palubes;	
	for (int i = 0; i < count_palubes; i++) 
	{
		LivePalubs.push_back(true);
	}
}

Ship::~Ship()
{
}

bool Ship::DoesShipLive()
{
	return LivePalubs.empty() ? false : true;
}

void Ship::setCP(int cp)
{
	this->count_palubes = cp;
}

int Ship::getCP() const
{
	return this->count_palubes;
}

Coordinates Ship::getCoordinates() const
{
	return this->coordinates;
}

void Ship::setCoorX(int x)
{
	this->coordinates.setX(x);
}

void Ship::serCoorY(int y)
{
	this->coordinates.setY(y);
}

void Ship::DelLivePalubs()
{
	this->LivePalubs.pop_back();
}

void Ship::AddXToVector(int x)
{
	this->xCoordinates.push_back(x);
}

vector<int> Ship::GetXCoorVector()
{
	return this->xCoordinates;
}

void Ship::AddYToVector(int y)
{
	this->yCoordinates.push_back(y);
}

vector<int> Ship::GetYCoorVector()
{
	return this->yCoordinates;
}
