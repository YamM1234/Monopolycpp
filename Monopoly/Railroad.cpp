#include "Railroad.h"
#include <iostream>
#include <algorithm>
#include "GameBoard.h"

using namespace std;

const int RAILROAD_COST{ 200 };


Railroad::Railroad(std::string name)
	:Buyable::Buyable(name, RAILROAD_COST)
{
}

void Railroad::onLand(GameBoard* board, Player* player)
{
	Buyable::onLand(board, player);
}

int Railroad::railroadCount()
{
	return 1;
}

void Railroad::viewProperty(Player* a)
{
	cout << "You have " << a->railRoadCount() << " railroad." << endl;
	string input;
	while (true) {
		cout << "Please [QUIT]." << endl;
		cin >> input;
		transform(input.begin(), input.end(), input.begin(), ::toupper);
		if (input == "QUIT") {
			return;
		}
		else {
			cout << "Try Again." << endl;
		}
	}
}

int Railroad::rent(GameBoard* board, Player* player)
{
	static const int costs[4]{ 25, 50, 100, 200 };
	return costs[owner->railRoadCount() - 1];
}
