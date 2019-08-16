#pragma once
#include "Coordinates.h"
#include <vector>

using namespace std;

enum Direction
{
	Horisontal = 0,
	Vertical = 1
};

class Ship
{
private:
	Coordinates coordinates;
	int count_palubes;
	vector<bool> LivePalubs;
	vector<int> xCoordinates;
	vector<int> yCoordinates;
public:
	Direction direction;		
	Ship();
	Ship(int _count_palubes);
	Ship(Coordinates _coordinates, Direction _direction, int _count_palubes);
	~Ship();	
	bool DoesShipLive();
	void setCP(int cp);		
	int getCP() const;
	Coordinates getCoordinates() const;
	void setCoorX(int x);
	void serCoorY(int y);
	void DelLivePalubs();
	void AddXToVector(int x);
	vector<int> GetXCoorVector();
	void AddYToVector(int y);
	vector<int> GetYCoorVector();
};

