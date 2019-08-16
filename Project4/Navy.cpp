#include "Navy.h"
#include "Map.h"
#include <iostream>
#include <ctime>

using namespace std;

Navy::Navy()
{
	ships[0] = Ship(4);
	ships[1] = Ship(3);
	ships[2] = Ship(3);
	ships[3] = Ship(2);
	ships[4] = Ship(2);
	ships[5] = Ship(2);
	ships[6] = Ship(1);
	ships[7] = Ship(1);
	ships[8] = Ship(1);
	ships[9] = Ship(1);

	//заповнюємо нуликами нашу карту, де будуть розміщатись кораблі
	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			NavyArea[x][y] = 0;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		cout << ships[i].getCP() << " ";
		ships[i] = SetPosition(ships[i]);
	}
}

Navy::~Navy()
{
}

Ship Navy::SetPosition(Ship ship)
{			
	int direction = rand() % +100;
	direction < 50 ? ship.direction = Horisontal : ship.direction = Vertical;
	bool res = false;
	while (true)
	{			
		ship.setCoorX(rand() % +10);
		ship.serCoorY(rand() % +10);
		if (ship.direction == Vertical)
		{
			if (ship.getCoordinates().getY() + ship.getCP() < 10)
			{
				bool vertical = true;
				//1 - якщо y = 0, x = 0 лівий нижній кут
				if (ship.getCoordinates().getY() == 0 && ship.getCoordinates().getX() == 0)
				{
					for (int y = ship.getCoordinates().getY(); y < ship.getCoordinates().getY() + ship.getCP() + 1; y++)
					{
						if (NavyArea[ship.getCoordinates().getX() + 1][y] > 0)
						{
							vertical = false;
							break;
						}
					}
					for (int y = ship.getCoordinates().getY(); y < ship.getCoordinates().getY() + ship.getCP() + 1; y++)
					{
						if (NavyArea[ship.getCoordinates().getX()][y] > 0)
						{
							vertical = false;
							break;
						}
					}
				}
				//2 - якщо y = 9, x = 0 лівий верхній кут
				else if (ship.getCoordinates().getY() == 9 && ship.getCoordinates().getX() == 0)
				{
					for (int y = ship.getCoordinates().getY(); y > ship.getCoordinates().getY() + ship.getCP() + 1; y--)
					{
						if (NavyArea[ship.getCoordinates().getX() + 1][y] > 0)
						{
							vertical = false;
							break;
						}
					}
					for (int y = ship.getCoordinates().getY(); y > ship.getCoordinates().getY() + ship.getCP() + 1; y--)
					{
						if (NavyArea[ship.getCoordinates().getX()][y] > 0)
						{
							vertical = false;
							break;
						}
					}
				}
				//3 - якщо y = 9, x = 9 - верхній правий кут 
				else if (ship.getCoordinates().getY() == 9 && ship.getCoordinates().getX() == 9)
				{
					for (int y = ship.getCoordinates().getY(); y > ship.getCoordinates().getY() + ship.getCP() + 1; y--)
					{
						if (NavyArea[ship.getCoordinates().getX() - 1][y] > 0)
						{
							vertical = false;
							break;
						}
					}
					for (int y = ship.getCoordinates().getY(); y > ship.getCoordinates().getY() + ship.getCP() + 1; y--)
					{
						if (NavyArea[ship.getCoordinates().getX()][y] > 0)
						{
							vertical = false;
							break;
						}
					}
				}
				//4 - якщо y = 0, x = 9 - нижній правий кут
				else if (ship.getCoordinates().getY() == 0 && ship.getCoordinates().getX() == 9)
				{

					for (int y = ship.getCoordinates().getY(); y < ship.getCoordinates().getY() + ship.getCP() + 1; y++)
					{
						if (NavyArea[ship.getCoordinates().getX() - 1][y] > 0)
						{
							vertical = false;
							break;
						}
					}
					for (int y = ship.getCoordinates().getY(); y < ship.getCoordinates().getY() + ship.getCP() + 1; y++)
					{
						if (NavyArea[ship.getCoordinates().getX()][y] > 0)
						{
							vertical = false;
							break;
						}
					}
				}
				//5 - якщо у = 0, x < 9 
				else if (ship.getCoordinates().getY() == 0 && ship.getCoordinates().getX() < 9)
				{
					for (int y = ship.getCoordinates().getY(); y < ship.getCoordinates().getY() + ship.getCP() + 1; y++)
					{
						if (NavyArea[ship.getCoordinates().getX() + 1][y] > 0)
						{
							vertical = false;
							break;
						}
					}
					for (int y = ship.getCoordinates().getY(); y < ship.getCoordinates().getY() + ship.getCP() + 1; y++)
					{
						if (NavyArea[ship.getCoordinates().getX()][y] > 0)
						{
							vertical = false;
							break;
						}
					}
					for (int y = ship.getCoordinates().getY(); y < ship.getCoordinates().getY() + ship.getCP() + 1; y++)
					{
						if (NavyArea[ship.getCoordinates().getX() - 1][y] > 0)
						{
							vertical = false;
							break;
						}
					}
				}
				//6 - якщо y < 9, x = 0
				else if (ship.getCoordinates().getY() < 9 && ship.getCoordinates().getX() == 0)
				{
					for (int y = ship.getCoordinates().getY() - 1; y < ship.getCoordinates().getY() + ship.getCP() + 1; y++)
					{
						if (NavyArea[ship.getCoordinates().getX() + 1][y] > 0)
						{
							vertical = false;
							break;
						}
					}
					for (int y = ship.getCoordinates().getY() - 1; y < ship.getCoordinates().getY() + ship.getCP() + 1; y++)
					{
						if (NavyArea[ship.getCoordinates().getX()][y] > 0)
						{
							vertical = false;
							break;
						}
					}
				}
				//7 - якщо y > 0 та x > 0 - корабель розміщений не торкаючись бортів
				else
				{
					for (int y = ship.getCoordinates().getY() - 1; y < ship.getCoordinates().getY() + ship.getCP() + 1; y++)
					{
						if (NavyArea[ship.getCoordinates().getX() - 1][y] > 0)
						{
							vertical = false;
							break;
						}
					}
					for (int y = ship.getCoordinates().getY() - 1; y < ship.getCoordinates().getY() + ship.getCP() + 1; y++)
					{
						if (NavyArea[ship.getCoordinates().getX()][y] > 0)
						{
							vertical = false;
							break;
						}
					}
					for (int y = ship.getCoordinates().getY() - 1; y < ship.getCoordinates().getY() + ship.getCP() + 1; y++)
					{
						if (NavyArea[ship.getCoordinates().getX() + 1][y] > 0)
						{
							vertical = false;
							break;
						}
					}
				}
				//якщо є можливість встановлення кораблика малюємо
				if (vertical)
				{
					for (int y = ship.getCoordinates().getY(); y < ship.getCoordinates().getY() + ship.getCP(); y++)
					{
						NavyArea[ship.getCoordinates().getX()][y] = ship.getCP();
						//встановлюємо координати корабля
						ship.AddXToVector(y);
						ship.AddYToVector(ship.getCoordinates().getX());

					}
					res = true;
				}
			}
		}
		else if (ship.direction == Horisontal)
		{
			if (ship.getCoordinates().getX() + ship.getCP() < 10)
			{
				bool horizontal = true;
				//1 - якщо x = 0, y = 0 лівий нижній кут				
				if (ship.getCoordinates().getX() == 0 && ship.getCoordinates().getY() == 0)
				{
					for (int x = ship.getCoordinates().getX(); x < ship.getCoordinates().getX() + ship.getCP() + 1; x++)
					{
						if (NavyArea[x][ship.getCoordinates().getY() + 1] > 0)
						{
							horizontal = false;
							break;
						}
					}
					for (int x = ship.getCoordinates().getX(); x < ship.getCoordinates().getX() + ship.getCP() + 1; x++)
					{
						if (NavyArea[x][ship.getCoordinates().getY()] > 0)
						{
							horizontal = false;
							break;
						}
					}
				}
				//2 - якщо x = 0  y = 9 лівий верхній кут
				else if (ship.getCoordinates().getX() == 0 && ship.getCoordinates().getY() == 9)
				{
					for (int x = ship.getCoordinates().getX(); x < ship.getCoordinates().getX() + ship.getCP() + 1; x++)
					{
						if (NavyArea[x][ship.getCoordinates().getY() - 1] > 0)
						{
							horizontal = false;
							break;
						}
					}
					for (int x = ship.getCoordinates().getX(); x < ship.getCoordinates().getX() + ship.getCP() + 1; x++)
					{
						if (NavyArea[x][ship.getCoordinates().getY()] > 0)
						{
							horizontal = false;
							break;
						}
					}
				}
				//3 - якщо x = 9, y = 9 - правий верхній кут 
				else if (ship.getCoordinates().getX() == 9 && ship.getCoordinates().getY() == 9)
				{
					for (int x = ship.getCoordinates().getX(); x > ship.getCoordinates().getX() + ship.getCP() + 1; x--)
					{
						if (NavyArea[x][ship.getCoordinates().getY() - 1] > 0)
						{
							horizontal = false;
							break;
						}
					}
					for (int x = ship.getCoordinates().getX(); x > ship.getCoordinates().getX() + ship.getCP() + 1; x--)
					{
						if (NavyArea[x][ship.getCoordinates().getY()] > 0)
						{
							horizontal = false;
							break;
						}
					}
				}
				//4 - якщо x = 9, y = 0 - правий нижній кут
				else if (ship.getCoordinates().getX() == 9 && ship.getCoordinates().getY() == 0)
				{
					for (int x = ship.getCoordinates().getX(); x > ship.getCoordinates().getX() + ship.getCP() + 1; x--)
					{
						if (NavyArea[x][ship.getCoordinates().getY() + 1] > 0)
						{
							horizontal = false;
							break;
						}
					}
					for (int x = ship.getCoordinates().getX(); x > ship.getCoordinates().getX() + ship.getCP() + 1; x--)
					{
						if (NavyArea[x][ship.getCoordinates().getY()] > 0)
						{
							horizontal = false;
							break;
						}
					}
				}
				//5 - якщо x = 0, y < 9
				else if (ship.getCoordinates().getX() == 0 && ship.getCoordinates().getY() < 9)
				{
					for (int x = ship.getCoordinates().getX(); x < ship.getCoordinates().getX() + ship.getCP() + 1; x++)
					{
						if (NavyArea[x][ship.getCoordinates().getY() - 1] > 0)
						{
							horizontal = false;
							break;
						}
					}
					for (int x = ship.getCoordinates().getX(); x < ship.getCoordinates().getX() + ship.getCP() + 1; x++)
					{
						if (NavyArea[x][ship.getCoordinates().getY()] > 0)
						{
							horizontal = false;
							break;
						}
					}
					for (int x = ship.getCoordinates().getX(); x < ship.getCoordinates().getX() + ship.getCP() + 1; x++)
					{
						if (NavyArea[x][ship.getCoordinates().getY() + 1] > 0)
						{
							horizontal = false;
							break;
						}
					}
				}
				//6 - якщо x < 9, y = 0
				else if (ship.getCoordinates().getX() < 9 && ship.getCoordinates().getY() == 0)
				{
					for (int x = ship.getCoordinates().getX() - 1; x < ship.getCoordinates().getX() + ship.getCP() + 1; x++)
					{
						if (NavyArea[x][ship.getCoordinates().getY()] > 0)
						{
							horizontal = false;
							break;
						}
					}
					for (int x = ship.getCoordinates().getX() - 1; x < ship.getCoordinates().getX() + ship.getCP() + 1; x++)
					{
						if (NavyArea[x][ship.getCoordinates().getY() + 1] > 0)
						{
							horizontal = false;
							break;
						}
					}
				}
				//7 - якщо y > 0 та x > 0  && y < 9 та x < 9			
				else
				{
					for (int x = ship.getCoordinates().getX() - 1; x < ship.getCoordinates().getX() + ship.getCP() + 1; x++)
					{
						if (NavyArea[x][ship.getCoordinates().getY() - 1] > 0)
						{
							horizontal = false;
							break;
						}
					}
					for (int x = ship.getCoordinates().getX() - 1; x < ship.getCoordinates().getX() + ship.getCP() + 1; x++)
					{
						if (NavyArea[x][ship.getCoordinates().getY()] > 0)
						{
							horizontal = false;
							break;
						}
					}
					for (int x = ship.getCoordinates().getX() - 1; x < ship.getCoordinates().getX() + ship.getCP() + 1; x++)
					{
						if (NavyArea[x][ship.getCoordinates().getY() + 1] > 0)
						{
							horizontal = false;
							break;
						}
					}
				}
				//якщо є можливість розміщення - малюємо
				if (horizontal)
				{
					for (int x = ship.getCoordinates().getX(); x < ship.getCoordinates().getX() + ship.getCP(); x++)
					{
						//це для промальовки в 2 м.масиві
						NavyArea[x][ship.getCoordinates().getY()] = ship.getCP();
						//встановлюємо координати корабля
						ship.AddXToVector(x);
						ship.AddYToVector(ship.getCoordinates().getY());
					}
					res = true;
				}
			}
		}
		if (res) break;
	}
	return ship;
}

void Navy::WhenShipIsSunk(int shipNumber)
{
	int x = ships[shipNumber].getCoordinates().getX();
	int y = ships[shipNumber].getCoordinates().getY();
	int countpalubes = ships[shipNumber].getCP();

	//якщо корабель розміщено горизонтально - у - незмінний
	if (ships[shipNumber].direction == Horisontal)
	{				
		if (x == 0 && y == 0)
		{
			for (int i = x; i < countpalubes + 1; i++)
			{
				NavyArea[i][y + 1] = -10;
			}
			NavyArea[x + countpalubes][y] = -10;
		}
		else if (x == 0 && y == 9)
		{
			for (int i = x; i < countpalubes + 1; i++)
			{
				NavyArea[i][y - 1] = -10;
			}
			NavyArea[x + countpalubes][y] = -10;
		}
		else if (x == 9 && y == 9)
		{
			for (int i = x; i > x + countpalubes + 1; i--)
			{
				NavyArea[i][y - 1] = -10;
			}
			NavyArea[x - countpalubes][y] = -10;
		}
		else if (x == 9 && y == 0)
		{
			for (int i = x; i > x + countpalubes + 1; i--)
			{
				NavyArea[i][y + 1] = -10;
			}
			NavyArea[x - countpalubes][y] = -10;
		}		
		else if (x == 0 && y > 0)
		{
			for (int i = x; i < countpalubes + 1; i++)
			{
				NavyArea[i][y + 1] = -10;
				NavyArea[i][y - 1] = -10;
			}
			NavyArea[x + countpalubes][y] = -10;
		}
		else if (x == 9 && y > 0)
		{
			for (int i = x; i > x + countpalubes + 1; i--)
			{
				NavyArea[i][y + 1] = -10;
				NavyArea[i][y - 1] = -10;
			}
			NavyArea[x - countpalubes][y] = -10;
		}		
		else if (x > 0 && y == 0)
		{
			for (int i = x-1; i < x+countpalubes+1; i++)
			{
				NavyArea[i][y + 1] = -10;
			}
			NavyArea[x - 1][y] = -10;
			NavyArea[x + countpalubes][y] = -10;
		}
		else if (x > 0 && y == 9)
		{
			for (int i = x - 1; i < x + countpalubes + 1; i++)
			{
				NavyArea[i][y - 1] = -10;
			}
			NavyArea[x-1][y] = -10;
			NavyArea[x + countpalubes][y] = -10;
		}
		else if (x > 0 && y > 0 && y < 9 && x < 9)
		{
			for (int i = x - 1; i < x + countpalubes + 1; i++)
			{
				NavyArea[i][y + 1] = -10;
				NavyArea[i][y - 1] = -10;
			}
			NavyArea[x - 1][y] = -10;
			NavyArea[x + countpalubes][y] = -10;
		}
	}
	//якщо корабель розміщено вертикально - x - незмінний
	if (ships[shipNumber].direction == Vertical)
	{
		if (x == 0 && y == 0)
		{
			for (int i = y; i < countpalubes + 1; i++)
			{
				NavyArea[x + 1][i] = -10;
			}
			NavyArea[x][y + countpalubes] = -10;
		}
		else if (x == 0 && y == 9)
		{
			for (int i = y; i < countpalubes + 1; i++)
			{
				NavyArea[x + 1][i] = -10;
			}
			NavyArea[x][y + countpalubes] = -10;
		}		
		else if (x == 9 && y == 9)
		{
			for (int i = y; i > y + countpalubes + 1; i--)
			{
				NavyArea[x - 1][i] = -10;
			}
			NavyArea[x][y - countpalubes] = -10;
		}	
		else if (x == 9 && y == 0)
		{
			for (int i = y; i < countpalubes + 1; i++)
			{
				NavyArea[x - 1][i] = -10;
			}
			NavyArea[x][y + countpalubes] = -10;
		}		
		else if (x == 0 && y > 0)
		{
			for (int i = y - 1; i < y + countpalubes + 1; i++)
			{
				NavyArea[x + 1][i] = -10;
			}
			NavyArea[x][y + countpalubes] = -10;
			NavyArea[x][y - 1] = -10;
		}
		else if (x == 9 && y > 0)
		{
			for (int i = y - 1; i < y + countpalubes + 1; i++)
			{
				NavyArea[x - 1][i] = -10;
			}
			NavyArea[x][y + countpalubes] = -10;
			NavyArea[x][y - 1] = -10;
		}		
		else if (x > 0 && y == 0)
		{
			for (int i = y; i < countpalubes + 1; i++)
			{
				NavyArea[x + 1][i] = -10;
				NavyArea[x - 1][i] = -10;
			}
			NavyArea[x][y + countpalubes] = -10;
		}
		else if (x > 0 && y == 9)
		{
			for (int i = y; i < countpalubes + 1; i++)
			{
				NavyArea[x - 1][y] = -10;
				NavyArea[x + 1][y] = -10;
			}
			NavyArea[x][y - countpalubes] = -10;
		}
		else if (x > 0 && y > 0 && y < 9 && x < 9)
		{
			for (int i = y - 1; i < y + countpalubes + 1; i++)
			{
				NavyArea[x + 1][i] = -10;
				NavyArea[x - 1][i] = -10;
			}
			NavyArea[x][y - 1] = -10;
			NavyArea[x][y + countpalubes] = -10;
		}
	}
}

void Navy::ChangeNavy(int xa, int yb)
{
	if (NavyArea[yb - 2][xa - 1] > 0)
	{
		NavyArea[yb - 2][xa - 1] *= -1;
		int a = xa - 1;
		int b = yb - 2;
		//тут перебираємо кораблики вертикально розміщені
		for (int i = 0; i < 10; i++)
		{
			for (int x = 0; x < ships[i].GetXCoorVector().size(); x++)
			{
				for (int y = 0; y < ships[i].GetYCoorVector().size(); y++)
				{
					//якщо координати збіглись - видалаємо кількість живих палуб
					if (ships[i].GetXCoorVector()[x] == a &&
						ships[i].GetYCoorVector()[y] == b && 
						ships[i].direction == Vertical)
					{
						ships[i].DelLivePalubs();
						break;						
					}
					else if (ships[i].GetXCoorVector()[x] == b &&
						ships[i].GetYCoorVector()[y] == a &&
						ships[i].direction == Horisontal)
					{
						ships[i].DelLivePalubs();
						break;						
					}
				}

			}
		}	
	}
	else if (NavyArea[yb - 2][xa - 1] == 0)
	{
		NavyArea[yb - 2][xa - 1] = -10;
	}
}

bool Navy::EmptyCell(int x, int y)
{
	bool isEmpty = false;
	if (NavyArea[y - 2][x - 1] >= 0 ||
		NavyArea[y - 2][x - 1] == 0)
	{
		isEmpty = true;
	}
	return isEmpty;
}

bool Navy::DoesItHit(int x, int y)
{
	return NavyArea[y-2][x-1] > 0 && NavyArea[y-2][x-1] < 5 ? true : false;
}

