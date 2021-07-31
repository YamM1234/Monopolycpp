#include <iostream>
#include <algorithm>
#include "IncomeTax.h"
#include "GameBoard.h"

using namespace std;

int BILL = 200;
int TAX_DIVISOR = 10;

void IncomeTax::onLand(GameBoard* board, Player* player)
{
	string input;
	cout << "Would you like to pay $200 or pay 10% equivalent of your total assets" << endl;
	cout << "Pay a [BILL] of 200 or pay a [TAX] of 10%: " << endl;
	while (true) {
		cin >> input;
		transform(input.begin(), input.end(), input.begin(), ::toupper);
		if (input == "a")
		{
			board->changeMoney(player, -BILL);
			break;
		}
		else if (input == "b")
		{
			int result = player->totalAssets() / TAX_DIVISOR;
			if (player->totalAssets() % 10) {
				result++;
			}
			else { ; }
			board->changeMoney(player, -result);
			break;
		}
		else
		{
			;
		}
	}
}

IncomeTax::IncomeTax(std::string name)
	: Event::Event(name)
{
}
