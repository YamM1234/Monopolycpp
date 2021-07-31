#include <stdio.h>
#include "GameBoard.h"
#include <iostream>
#include <algorithm>


/*Accomplished requirements for 70%
Implemented: 
Cards(Chance and Community),
Houses,
Multiplayer,
Doubles,
Cheats*/

using namespace std;
int main(int argc, char* argv[])
{
	GameBoard game{};
	vector<Player> listOfPlayers{};
	while (true) {
		cout << "Players : " << listOfPlayers.size() << endl;
		cout << "Would you like to add player? [YES] or [NO] " << endl;
		string input;
		cin >> input;
		transform(input.begin(), input.end(), input.begin(), ::toupper);
		if (input == "YES") {
			cout << "Write name: " << endl;
			string name;
			cin >> name;
			listOfPlayers.push_back(Player(name));
		}
		else if (input == "NO") {
			if (listOfPlayers.size() < 2) {
				cout << "Not enough players" << endl;
			}
			else {
				break;
			}
		}
		else {
			cout << "Please enter the right word." << endl;
		}
	}
	for (size_t i = 0; i < listOfPlayers.size(); i++)
	{
		game.listOfPlayers.push_back(&listOfPlayers[i]);
	}
	game.startGame();
}