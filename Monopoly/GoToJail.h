#pragma once
#include "EventCards.h"


class GoToJail : public EventCards
{
public:
	GoToJail(std::string message);
	void onUse(GameBoard* board, Player* player);

private:

};
