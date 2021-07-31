#pragma once
#include "Event.h"
class GoToJailTile : public Event
{
public:
	GoToJailTile(std::string name);
	void onLand(GameBoard* board, Player* player);

public:

};