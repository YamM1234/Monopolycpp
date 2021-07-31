#include "payMoney.h"
#include "GameBoard.h"

payMoney::payMoney(std::string message, int amount)
	: EventCards::EventCards(message), amount{ amount }
{
}

void payMoney::onUse(GameBoard* board, Player* player)
{
	EventCards::onUse(board, player);
	board->changeMoney(player, -amount);
}
