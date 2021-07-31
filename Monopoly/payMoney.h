#pragma once
#include "EventCards.h"

class payMoney : public EventCards
{
public:
	payMoney(std::string message, int amount);
	void onUse(GameBoard* board, Player* player);

public:
	int amount;
};
