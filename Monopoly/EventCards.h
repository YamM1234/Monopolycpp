#pragma once
#include <string>

class GameBoard;
class Player;

class EventCards
{
public:
	EventCards(std::string message);
	virtual void onUse(GameBoard* board, Player* player);
public:
	std::string message;
};
