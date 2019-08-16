#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include "Ship.h"
#include "Map.h"
#include "Navy.h"
#include "Game.h"

using namespace std;

struct CursorPos
{
	int x = 1; // default value
	int y = 2; // default value 
};

CursorPos makeMove(int, CursorPos&);
int way = 0;
void gotoxy(short, short);

int main()
{
	setlocale(LC_ALL, "");
	srand(time(0));
	CursorPos cursorPos;
	Map *map = new Map();	
	Game game;	
	Navy *navyUser = new Navy();
	Navy *navyPc = new Navy();
	
	gotoxy(cursorPos.x, cursorPos.y);
	while (game.AreWePlaying(*navyUser, *navyPc))
	{
		while (true)
		{
			way = _getch();
			if (way == 75 || way == 72 || way == 77 || way == 80)
			{
				cursorPos = makeMove(way, cursorPos);
			}
			else if (way == 32)
			{
				if (game.ShutUser(*navyPc, cursorPos.x, cursorPos.y, *navyUser) &&
					game.AreWePlaying(*navyUser,*navyPc))
				{
					continue;
					game.ShutUser(*navyPc, cursorPos.x, cursorPos.y, *navyUser);														
				}
				else
				{
					game.SetDoesItUser(false);
					break;
				}
			}
		}
		game.ShutPC(*navyUser);
		system("cls");
		map->ChooseCol(6, 0);
		cout << "PC game area\n";
		map->ChooseCol(7, 0);
		map->Display(navyPc->NavyArea);
		map->ChooseCol(9, 0);
		cout << "User game area\n";
		map->ChooseCol(7, 0);
		map->Display(navyUser->NavyArea);
		gotoxy(cursorPos.x, cursorPos.y);		
	}
	return 0;
}

void gotoxy(short x, short y)
{
	COORD pos = { x, y };
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(output, pos);
}

CursorPos makeMove(int way, CursorPos &myturn)
{
	if (way == 75 && myturn.x - 1 > 0) myturn.x--;
	else if (way == 72 && myturn.y - 1 > 1) myturn.y--;
	else if (way == 77 && myturn.x + 1 <= 10) myturn.x++;
	else if (way == 80 && myturn.y + 1 <= 11) myturn.y++;
	gotoxy(myturn.x, myturn.y);
	return myturn;
}
