#include "Utilities.h"
#include <iostream>
#include <algorithm>
#include "GameBoard.h"

const int UTILITIES_COST{ 150 };

using namespace std;

Utilities::Utilities(std::string name)
	:Buyable::Buyable(name,UTILITIES_COST)
{
}

int Utilities::rent(GameBoard* board, Player* player) {
	static const int mult[2]{ 4, 10 };
	return (mult[player->utilityCount() - 1]) * (board->lastDiceRoll.first + board->lastDiceRoll.second);
}

int Utilities::utilityCount()
{
	return 1;
}

void Utilities::viewProperty(Player* a)
{
	cout << "You have " << a->utilityCount() << " utilities." << endl;
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
