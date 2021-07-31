#pragma once
#include "EventCards.h"

class MovementCard : public EventCards
{
public:
	MovementCard(std::string message, int destination);
	void onUse(GameBoard* board, Player* player);

public:
	const int destination;
};
