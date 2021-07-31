#pragma once
#include "vector"
#include "Buyable.h"
#include "Player.h"
const int JAIL_POS{ 10 };
const int JAIL_FINE{ 50 };

class GameBoard
{
public:
	GameBoard(); //instantiate after all objects are created
	~GameBoard();
	void assignProperty(Player* a, Buyable* b);
	void changeMoney(Player* a, int b);
	int totalDiceRoll();
	void goToJail(Player* a);
	std::vector<Player*>::iterator bankruptcy(Player* a);
	void playerAction(Player* a);
	void viewProperties(Player* a);
	void viewProperty(Player* a, Buyable* b);
	void movePlayer(Player* a);
	bool jailedPlayerMove(Player* a);
	bool nonJailedPlayerMove(Player* a);
	void addPlayer(Player* a);
	void startGame();

public:
	Tile* board[40];
	std::pair<int, int> lastDiceRoll;
	bool canMoveAgain;
	int doubleCount;
	std::vector<Player*> listOfPlayers;
};