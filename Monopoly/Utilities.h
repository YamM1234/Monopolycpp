#pragma once
#include "Buyable.h"
class Utilities : public Buyable
{
public:
	Utilities(std::string name);
	int utilityCount();
	void viewProperty(Player* a);
	int rent(GameBoard* board, Player* player);

public:

};