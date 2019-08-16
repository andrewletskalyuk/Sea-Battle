#pragma once
#include "Navy.h"
#include "Map.h"

class Game : Map
{	
	bool doesItUser;
public:
	Game();
	~Game();
	void SetDoesItUser(bool _doesItUser);
	bool GetDoesItUser() const;
	bool AreWePlaying(Navy& user, Navy& pc);
	bool ShutUser(Navy & navyPC, int x, int y, Navy & navyUser);
	void ShutPC(Navy & navyUser);
};

