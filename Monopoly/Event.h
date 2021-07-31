#pragma once
#include "Tile.h"
class Event : public Tile
{
public:
	Event(std::string name);
	virtual void onLand(GameBoard* board, Player* player);
};