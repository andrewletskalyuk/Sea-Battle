#pragma once

class Map
{
public:
	Map();
	~Map();
	char MapArea[10][10];
	void Display(int _space[][10]);
	void ChooseCol(int, int);
};

