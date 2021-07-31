#pragma once
#include "EventCards.h" 

class getMoney : public EventCards
{
public:
	getMoney(std::string message, int amount);
	void onUse(GameBoard* board, Player* player);

public:
	int amount;
};