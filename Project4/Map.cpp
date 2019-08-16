#include "Map.h"
#include "Navy.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

Map::Map()
{
}

Map::~Map()
{
}

void Map::Display(int _space[][10])
{
	string A = " ABCDEFGHIJ";
	cout << A << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << i;
		for (int j = 0; j < 10; j++)
		{
			if (_space[i][j] == 0 || _space[i][j] > 0)
			{
				cout << " ";
			}
			else if (_space[i][j] == -10)
			{	
				ChooseCol(14, 0);
				cout << "#";
				ChooseCol(7, 0);
			}
			else if (_space[i][j] < 0)
			{	
				ChooseCol(12, 0);
				cout << "X";
				ChooseCol(7, 0);
			}
		}
		cout << "|\n";
	}
}

void Map::ChooseCol(int symbols, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | symbols));
}
