#pragma once
#include <string>
#include "Event.h"

class IncomeTax : public Event
{
public:
	IncomeTax(std::string name);
	void onLand(GameBoard* board, Player* player);

public:

};
