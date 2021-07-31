#include "Player.h"
#include "Buyable.h"
#include <iostream>
const int STARTING_MONEY{ 1500 };

Player::Player(std::string const name)
	:name{ name }, balance{ STARTING_MONEY }, properties(), JailCard{ 0 }, inJail{ false }, currPos{ 0 }
{
}

int Player::railRoadCount()
{
	int sum{ 0 };
	for (std::vector<Buyable*>::iterator i = properties.begin(); i != properties.end(); ++i) {
		sum += (*i)->assetprice();
	}
	return sum;
}

int Player::utilityCount()
{
	int sum{ 0 };
	for (std::vector<Buyable*>::iterator i = properties.begin(); i != properties.end(); ++i) {
		sum += (*i)->utilityCount();
	}
	return sum;
}

int Player::totalAssets()
{
	int sum{ 0 };
	for (std::vector<Buyable*>::iterator i = properties.begin(); i != properties.end(); ++i) {
		sum += (*i)->railroadCount();
	}
	return sum;
}

int Player::totalPropertyCount()
{
	return properties.size();
}

int Player::unmortgagedPropertiesCount()
{
	int sum{ 0 };
	for (std::vector<Buyable*>::iterator i = properties.begin(); i != properties.end(); ++i) {
		if (!(*i)->isMortgaged)
		{
			sum++;
		}
		else { ; }
	}
	return sum;
}

std::ostream& operator<<(std::ostream& out, const Player& player)
{
	out << "Player: " << player.name << std::endl;
	out << "Balance: " << player.balance << std::endl;
	return out;
}
