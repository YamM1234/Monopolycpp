#include "GameBoard.h"
#include <iostream>
#include<ctype.h>
#include<algorithm>
#include <random>
#include <time.h>
#include "Property.h"
#include "Event.h"
#include "EventCards.h"
#include "Chance.h"
#include "IncomeTax.h"
#include "Railroad.h"
#include "Utilities.h"
#include "GoToJailTile.h"
#include "LuxuryTax.h"
#include "AllEventCards.h"
#include "Printer.h"
#include "Cheats.h"

using namespace std;

const int CHANCE_POS[3]{ 7,22,36 };
const int COMMUNITY_POS[3]{ 2,17,33 };

const std::string CHEAT_MENU{ "THEREISNOCOWLEVEL" };


GameBoard::GameBoard()
	: lastDiceRoll(), canMoveAgain{ true }, listOfPlayers(), doubleCount{ 0 }
{
	Chance* chance = new Chance("Chance");
	Chance* community = new Chance("Community Chest");
	board[0] = new Event("Go!");
	board[1] = new Property("Mediterranean Avenue", 60, 50, 2, 10, 30, 90, 160, 250);
	//board[2] = community;
	board[3] = new Property("Baltic Avenue", 60, 50, 4, 20, 60, 180, 320, 450);
	board[4] = new IncomeTax("Income Tax");
	board[5] = new Railroad("Reading Railroad");
	board[6] = new Property("Oriental Avenue", 100, 50, 6, 30, 90, 270, 400, 550);
	//board[7] = chance;
	board[8] = new Property("Vermont Avenue", 100, 50, 6, 30, 90, 270, 400, 550);
	board[9] = new Property("Conneticut Avenue", 120, 50, 8, 40, 100, 300, 450, 600);
	board[10] = new Event("Just Visiting");
	board[11] = new Property("St. Charles Place", 140, 100, 10, 50, 150, 450, 625, 750);
	board[12] = new Utilities("Electric Company");
	board[13] = new Property("States Avenue", 140, 100, 10, 50, 150, 450, 625, 750);
	board[14] = new Property("Virginia Avenue", 160, 100, 12, 60, 180, 500, 700, 900);
	board[15] = new Railroad("Pennsylvania Railroad");
	board[16] = new Property("St. James Place", 180, 100, 14, 70, 200, 550, 750, 950);
	//board[17] = community;
	board[18] = new Property("Tennessee Avenue", 180, 100, 14, 70, 200, 550, 750, 950);
	board[19] = new Property("New York Ave", 200, 100, 16, 80, 220, 600, 800, 1000);
	board[20] = new Event("Free Parking");
	board[21] = new Property("Kentucky Ave", 220, 150, 18, 90, 250, 700, 875, 1050);
	//board[22] = chance;
	board[23] = new Property("Indiana Ave", 220, 150, 18, 90, 250, 700, 875, 1050);
	board[24] = new Property("Illinois Ave", 240, 150, 20, 100, 300, 750, 925, 1100);
	board[25] = new Railroad("B&O Railroad");
	board[26] = new Property("Atlantic Ave", 260, 150, 22, 110, 330, 800, 975, 1150);
	board[27] = new Property("Ventnor Ave", 260, 150, 22, 110, 330, 800, 975, 1150);
	board[28] = new Utilities("Water Works");
	board[29] = new Property("Marvin Gardens", 280, 150, 24, 120, 360, 850, 1025, 2500);
	board[30] = new GoToJailTile("Go To Jail");
	board[31] = new Property("Pacific Ave", 300, 200, 26, 130, 390, 900, 1100, 1275);
	board[32] = new Property("North Carolina Ave", 300, 200, 26, 130, 390, 900, 1100, 1275);
	//board[33] = community;
	board[34] = new Property("Pennsylvania Ave", 320, 200, 28, 150, 450, 1000, 1200, 1400);
	board[35] = new Railroad("Short Line");
	//board[36] = chance;
	board[37] = new Property("Park Place", 350, 200, 35, 175, 500, 1100, 1300, 1500);
	board[38] = new LuxuryTax("Luxury Tax");
	board[39] = new Property("BoardWalk", 400, 200, 50, 200, 600, 1400, 1700, 2000);
	for (size_t i = 0 ; i < size(CHANCE_POS); i++)
	{
		board[CHANCE_POS[i]] = chance;
	}
	for (size_t i = 0; i < size(COMMUNITY_POS); i++)
	{
		board[COMMUNITY_POS[i]] = community;
	}
	chance->cards.push_back(new MovementCard("Advance to \"Go\" Collect 200", 0));
	community->cards.push_back(new capitalismCard("It's your Birthday, collect 10 from every player", 10));
	chance->cards.push_back(new CommunismCard("You have been elected Chairman of the Board. Pay each player 50", 50));
	community->cards.push_back(new getMoney("Bank error in your favor. Collect 200", 200));
	chance->cards.push_back(new payMoney("Pay poor tax of 15", 15));
	chance->cards.push_back(new RelativeMovementCard("Go Back Three {3} Spaces", 3));
	community->cards.push_back(new getMoney("Income tax refund. Collect 20", 20));
	chance->cards.push_back(new payMoney("You dropped 50 bill on the ground...", 50));
	community->cards.push_back(new getMoney("You inherit 100", 100));
	chance->cards.push_back(new getMoney("Receive 25 consultancy fee", 25));
}

GameBoard::~GameBoard()
{
	for (size_t i = 0; i < size(board)
		 && i != CHANCE_POS[1] && i != CHANCE_POS[2]
		 && i != COMMUNITY_POS[1] && i != COMMUNITY_POS[2]; i++)
	{
		delete board[i];
		board[i] = NULL;
	}
}


void GameBoard::assignProperty(Player* a, Buyable* b)
{
	a->properties.push_back(b);
	b->owner = a;
}

void GameBoard::changeMoney(Player* a, int b)
{
	a->balance += b;
}

int GameBoard::totalDiceRoll()
{
	static default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	static uniform_int_distribution<int> diceRoll{ 1, 6 };
	lastDiceRoll.first = diceRoll(engine);
	lastDiceRoll.second = diceRoll(engine);
	return lastDiceRoll.first + lastDiceRoll.second;
}

void GameBoard::goToJail(Player* a)
{
	cout << a->name << " is now in jail." << endl;
	a->inJail = true;
	a->currPos = JAIL_POS;
}

std::vector<Player*>::iterator GameBoard::bankruptcy(Player* a)
{
	cout << "We declare you bankrupt! HAHA!!" << endl;
	for (size_t i = 0; i < a->properties.size(); i++)
	{
		a->properties[i]->resetProperty();
	}
	return listOfPlayers.erase(std::find(listOfPlayers.begin(), listOfPlayers.end(), a));
}

void GameBoard::playerAction(Player* a)
{
	string input;
	while (true) {
		cout << *a;
		cout << "What would you like to do: " << endl;
		cout << "[VIEW] properties or [MOVE]: " << endl;
		cin >> input;
		transform(input.begin(), input.end(), input.begin(), ::toupper);
		if (input == "VIEW") {
			this->viewProperties(a);
		}
		else if (input == "MOVE") {
			this->movePlayer(a);
			break;
		}
		else if (input == CHEAT_MENU) {
			cout << "[A]dd money or [T]eleport player or [QUIT]" << endl;
			cin >> input;
			transform(input.begin(), input.end(), input.begin(), ::toupper);
			if (input == "A") {
				int amount{0};				
				cout << "How much money would you like?" << endl;
				while (!(cin >> amount)) {
					cin.clear();
					cout << "Please enter a valid integer" << endl;
				}
				addMoneyCheat(a, amount);
				break;
			}
			else if (input == "T") {
				int pos{ 0 };
				cout << "On which index would you like to teleport" << endl;
				while (!(cin >> pos && pos >= 0 && pos < 40)) {
					cin.clear();
					cout << "Pleae enter an integer between 0 and 39 inclusive" << endl;
				}
				teleportCheat(a, pos);
				break;
			}
			else if (input == "QUIT") {
				break;
			}
			else {
				cout << "Invalid choice, going back to main menu." << endl;
			}
		}
		else { cout << "Invalid answer, please type either view or move" << endl; }
	}
}

void GameBoard::viewProperties(Player* a)
{
	string input;
	bool isValid;
	while (true) {
		isValid = false;
		cout << "Type the name of the property to view or [QUIT]." << endl;
		cout << "Your Properties:" << endl;
		for (size_t i = 0; i < a->properties.size(); i++)
		{
			cout << a->properties[i]->name << endl;
		}
		cin >> ws;
		getline(cin, input);
		transform(input.begin(), input.end(), input.begin(), ::toupper);
		for (size_t i = 0; i < a->properties.size(); i++)
		{
			string name = a->properties[i]->name;
			string upperName{};
			upperName.resize(name.size());
			transform(name.begin(), name.end(), upperName.begin(), ::toupper);
			if (input == upperName) {
				isValid = true;
				this->viewProperty(a, a->properties[i]);
			}
		}
		if (input == "QUIT") {
			return;
		}
		if (!isValid) {
			cout << "You entered an invalid command. Please try again." << endl;
		}
	}
}

void GameBoard::viewProperty(Player* a, Buyable* b)
{
	b->viewProperty(a);
}

void GameBoard::movePlayer(Player* a)
{
	canMoveAgain = true;
	doubleCount = 0;
	while (canMoveAgain) {
		printBoard(this);
		if (a->inJail) {
			canMoveAgain = jailedPlayerMove(a);
		}
		if (canMoveAgain) {
			canMoveAgain = nonJailedPlayerMove(a);
		}
	}
}

bool GameBoard::jailedPlayerMove(Player* a)
{
	cout << "You are in Jail" << endl;
	cout << "Would you like to [PAY] $50, [USE] a JailCard or [ROLL] the dice and try to get a double: ";
	string input;
	while (true) {
		cin >> input;
		transform(input.begin(), input.end(), input.begin(), ::toupper);
		if (input == "PAY") {
			if (a->balance > JAIL_FINE) {
				this->changeMoney(a, -JAIL_FINE);
				a->inJail = !a->inJail;
				cout << "Fine paid, you are free from jail" << endl;
				return true;
			}
			else {
				cout << "Insufficient Funds" << endl;
				return false;
			}
		}
		if (input == "USE") {
			if (a->JailCard > 0) {
				a->JailCard--;
				a->inJail = !a->inJail;
				cout << "Jail Card used, you are free from jail" << endl;
				return true;
			}
			else {
				cout << "Not enough JailCards" << endl;
				return false;
			}
		}
		if (input == "ROLL") {
			int move = totalDiceRoll();
			if (lastDiceRoll.first == lastDiceRoll.second) {
				a->inJail = !a->inJail;
				cout << "Succesfully rolled a double, you are free from jail" << endl;
				a->currPos = (a->currPos + move) % 40;
				this->board[a->currPos]->onLand(this, a);
			}
			else {
				cout << "You are stuck in Jail" << endl;
			}
			return false;
		}
	}
}

bool GameBoard::nonJailedPlayerMove(Player* a)
{
	cout << "[ROLL] dice" << endl;
	string input;
	while (true) {
		cin >> input;
		transform(input.begin(), input.end(), input.begin(), ::toupper);
		if (input == "ROLL") {
			int move = totalDiceRoll();
			cout << "Rolled " << lastDiceRoll.first << " and " << lastDiceRoll.second << endl;
			if (lastDiceRoll.first == lastDiceRoll.second) {
				cout << "Rolled a double" << endl;
				doubleCount++;
			}
			if (doubleCount == 3) {
				this->goToJail(a);
				return false;
			}
			cout << "Moving " << move << " spaces " << endl;
			int prevPos = a->currPos;
			a->currPos = (a->currPos + move) % 40;
			if (prevPos > a->currPos) {
				this->changeMoney(a, 200);
				cout << "Passed Go tile, collect 200" << endl;
			}
			this->board[a->currPos]->onLand(this, a);
			return	canMoveAgain && lastDiceRoll.first == lastDiceRoll.second;
		}
		else {
			cout << "Invalid choice, please [ROLL]" << endl;
		}
	}
}

void GameBoard::addPlayer(Player* a)
{
	listOfPlayers.push_back(a);
}

void GameBoard::startGame()
{
	cout << "Welcome to Monopoly" << endl;
	cout << "Players:" << endl;
	for (size_t i = 0; i < this->listOfPlayers.size(); i++)
	{
		cout << "\t" << listOfPlayers[i]->name << endl;
	}
	for (std::vector<Player*>::iterator i = this->listOfPlayers.begin(); this->listOfPlayers.size() > 1; i++)
	{
		if (i == this->listOfPlayers.end()) i = this->listOfPlayers.begin();
		if ((*i)->balance <= 0) {
			i = bankruptcy(*i);
		}
		else {
			this->playerAction(*i);
		}
	}

}
