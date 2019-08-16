#include "Game.h"
#include <windows.h>
#include <iostream>

using namespace std;

Game::Game()
{
	this->doesItUser = rand() + 2;
}

Game::~Game()
{
}

void Game::SetDoesItUser(bool _doesItUser)
{
	this->doesItUser = _doesItUser;
}

bool Game::GetDoesItUser() const
{
	return this->doesItUser;
}

bool Game::AreWePlaying(Navy & user, Navy & pc)
{
	bool areweplaying = true;
	int countUser = 0;
	int countPC = 0;
	for (int i = 0; i < 10; i++)
	{
		if (!pc.ships[i].DoesShipLive())
		{
			countPC++;
			pc.WhenShipIsSunk(i);
		}
	}
	if (countPC == 10)
	{
		system("cls");
		HANDLE necessary = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(necessary, 14);
		cout << "Ви перемогли комп'ютер\n";
		system("pause");
		areweplaying = false;
	}
	for (int i = 0; i < 10; i++)
	{
		if (!user.ships[i].DoesShipLive())
		{
			countUser++;
			user.WhenShipIsSunk(i);
		}
	}
	if (countUser == 10)
	{
		system("cls");
		HANDLE necessary = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(necessary, 14);
		cout << "Комп'ютер перем1г\n";
		system("pause");
		areweplaying = false;
	}
	return areweplaying;
}

bool Game::ShutUser(Navy & navyPC, int x, int y, Navy& navyUser)
{
	bool hit = false;
	if (GetDoesItUser())
	{
		if (navyPC.DoesItHit(x,y))
		{			
			navyPC.ChangeNavy(x, y);
			//AreWePlaying(navyPC, navyUser);
			system("cls");
			Map::ChooseCol(6, 0);
			cout << "PC game area\n";
			Map::ChooseCol(7, 0);
			Map::Display(navyPC.NavyArea);
			Map::ChooseCol(9, 0);
			cout << "User game area\n";
			Map::ChooseCol(7, 0);
			Map::Display(navyUser.NavyArea);
			hit = true;
		}
		else
		{
			navyPC.ChangeNavy(x, y);
		}					
	}
	return hit;
}

void Game::ShutPC(Navy & navyUser)
{
	int x, y;
	//знаходимо пусту комірку
	do
	{
		x = rand() % +10 + 1;
		y = rand() % +10 + 2;
		
	} while (!navyUser.EmptyCell(x, y));	
	
	//якщо промазали - просто змінюємо ігрове поле
	if (!navyUser.DoesItHit(x,y))
	{
		navyUser.ChangeNavy(x, y);
	}
	//якщо влучили і поки влучаємо - продовжуємо стріляти
	else if(navyUser.DoesItHit(x,y))
	{					
		while (true)
		{
			navyUser.ChangeNavy(x, y);
			do
			{
				x = rand() % +10 + 1;
				y = rand() % +10 + 2;

			} while (!navyUser.EmptyCell(x, y));
			if (!navyUser.DoesItHit(x, y))
			{
				navyUser.ChangeNavy(x, y);
				break;
			}					
		}
	}	
	//коли не влучаємо - перехід ходу
	bool usertrue = true;
	SetDoesItUser(usertrue);
}
