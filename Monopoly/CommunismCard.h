#pragma once
#include "EventCards.h"

class CommunismCard : public EventCards
{
public:
	CommunismCard(std::string message, int amount);
	void onUse(GameBoard* board, Player* player);

public:
	int amount;
};