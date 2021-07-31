#pragma once
#include <string>
#include <vector>

class Buyable;

class Player
{
public:
	Player(std::string const name);
	int railRoadCount();
	int utilityCount();
	int totalAssets();
	int totalPropertyCount();
	int unmortgagedPropertiesCount();
	friend std::ostream& operator<< (std::ostream& out, const Player& player);

public:
	const std::string name;
	int balance;
	std::vector<Buyable*> properties;
	int JailCard;
	bool inJail;
	int currPos;
};