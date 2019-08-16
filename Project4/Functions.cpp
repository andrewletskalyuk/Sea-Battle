#include <iostream>
#include "Ship.h"
#include "Map.h"
#include "Navy.h"
#include <windows.h>
#include <conio.h>
#include <ctime>

int way = 0;
using namespace std;
bool isUser = false;
Navy *navyUser = new Navy();
Navy *navyPc = new Navy();
struct MyPosition
{
	int x;
	int y;
};
void makeMove(int way);
void gotoxy(int x, int y);
void Shut(MyPosition _MyWay);
MyPosition makeMove(int way, MyPosition _MyWay);
bool IsGameOver();