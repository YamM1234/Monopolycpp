#pragma once
#include "Tile.h"

class GameBoard;
class Player;

class Buyable : public Tile
{
public:
	Buyable(std::string name, int price);
	virtual void onLand(GameBoard* board, Player* player);
	virtual int railroadCount();
	virtual int utilityCount();
	virtual int assetprice();
	virtual void viewProperty(Player* a);
	virtual void resetProperty();
	virtual int rent(GameBoard* board, Player* player);

public:
	Player* owner{ NULL };
	bool isMortgaged{ false };
	int price;
};