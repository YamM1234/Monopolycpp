#include "CommunismCard.h"
#include "GameBoard.h"

CommunismCard::CommunismCard(std::string message, int amount)
	:EventCards::EventCards(message), amount{ amount }
{
}

void CommunismCard::onUse(GameBoard* board, Player* player)
{
	EventCards::onUse(board, player);
	for (auto i = board->listOfPlayers.begin(); i != board->listOfPlayers.end(); i++)
	{
		board->changeMoney(*i, amount);
		board->changeMoney(player, -amount);
	}
}
