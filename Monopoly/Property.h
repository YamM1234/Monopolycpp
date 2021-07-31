#pragma once
#include "Buyable.h"

class Property : public Buyable
{
public:
	Property(std::string name, int price, int costPerHouse,
		int rent0, int rent1, int rent2, int rent3, int rent4, int rent5);
	int rent(GameBoard* board, Player* player);
	int assetPrice();
	void viewProperty(Player* a);
	void resetProperty();
	friend std::ostream& operator << (std::ostream& out, const Property& c);

public:
	int level;
	int rents[6];
	int costPerHouse;
};