#pragma once
#include "Ship.h"
class Navy
{
public:
	Navy();
	~Navy();
	Ship ships[10];
	int NavyArea[10][10];
	Ship SetPosition(Ship);
	void WhenShipIsSunk(int);
	void ChangeNavy(int, int);
	bool EmptyCell(int, int);
	bool DoesItHit(int, int);
};

