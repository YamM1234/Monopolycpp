#pragma once
#include "EventCards.h"

class capitalismCard : public EventCards
{
public:
	capitalismCard(std::string message, int amount);
	void onUse(GameBoard* board, Player* player);

public:
	int amount;
};