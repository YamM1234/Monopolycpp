#pragma once
#include "Buyable.h"
class Railroad : public Buyable
{
public:
	Railroad(std::string name);
	void onLand(GameBoard* board, Player* player);
	int railroadCount();
	void viewProperty(Player* a);
	int rent(GameBoard* board, Player* player);

private:

};