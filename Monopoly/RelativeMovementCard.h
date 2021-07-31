#pragma once
#include "EventCards.h"
class RelativeMovementCard : public EventCards
{
public:
	RelativeMovementCard(std::string message, int move);
	void onUse(GameBoard* board, Player* player);

public:
	const int move;

};
