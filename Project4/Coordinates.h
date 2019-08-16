#pragma once
class Coordinates
{
	int x;
	int y;
public: 	
	Coordinates();
	Coordinates(int, int);
	~Coordinates();
	void setX(int _x);
	void setY(int _y);
	int getX() const;
	int getY() const;
};