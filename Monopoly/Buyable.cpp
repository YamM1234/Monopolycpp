#include "Buyable.h"
#include <iostream>
#include <algorithm>
#include "GameBoard.h"

using namespace std;

Buyable::Buyable(string name, int price)
	:Tile::Tile(name), price{ price }, owner{ NULL }, isMortgaged{ false }
{
}

void Buyable::onLand(GameBoard* board, Player* player)
{
	Tile::onLand(board, player);
	if (owner == NULL)
	{
		string input;
		cout << "What would you like to do?" << endl;
		cout << "[BUY] or [PASS]: " << endl;
		while (true) {
			cin >> input;
			transform(input.begin(), input.end(), input.begin(), ::toupper);
			if (input == "BUY")
			{
				if (player->balance > this->price) {
					board->changeMoney(player, -price);
					board->assignProperty(player, this);
					cout << "Property succesfully bought" << endl;
				}
				else {
					cout << "Insufficient Funds" << endl;
				}

				break;
			}
			else if (input == "PASS")
			{
				break;
			}
			else
			{
				cout << "Input is invalid" << endl;
				cout << "[BUY] or [PASS]: " << endl;
			}
		}
		board->canMoveAgain = true;
	}
	else if (owner != NULL && owner != player)
	{
		cout << this->name << " owned by " << owner->name << endl;
		cout << player->name << " pays " << this->rent(board, player) << endl;
		board->changeMoney(player, -(this->rent(board, player))); // get rekt son!!
	}
}

int Buyable::railroadCount()
{
	return 0;
}

int Buyable::utilityCount()
{
	return 0;
}

int Buyable::assetprice()
{
	if (isMortgaged)
	{
		return price / 2;
	}
	else 
	{
		return price;
	}
}

void Buyable::viewProperty(Player* a)
{
	;
}

void Buyable::resetProperty()
{
	this->owner = NULL;
}

int Buyable::rent(GameBoard* board, Player* player)
{
	return 0;
}
