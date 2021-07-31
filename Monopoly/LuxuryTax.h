#pragma once
#include <string>
#include "Event.h"


class LuxuryTax : public Event
{
public:
	LuxuryTax(std::string name);
	void onLand(GameBoard* board, Player* player);
private:

};
