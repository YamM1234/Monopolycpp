#pragma once
#include <string>
#include <vector>
#include "EventCards.h"
#include "Event.h"
class Chance : public Event
{
public:
	Chance(std::string name);
	~Chance();
	void onLand(GameBoard* board, Player* player);
public:
	std::vector<EventCards*> cards;
};
