#include "getMoney.h"
#include "GameBoard.h"

getMoney::getMoney(std::string message, int amount)
	: EventCards::EventCards(message), amount{amount}
{
}

void getMoney::onUse(GameBoard* board, Player* player)
{
	EventCards::onUse(board, player);
	board->changeMoney(player, amount);
}
