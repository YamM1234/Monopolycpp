#include "capitalismCard.h"
#include "GameBoard.h"

capitalismCard::capitalismCard(std::string message, int amount)
	:EventCards::EventCards(message), amount { amount }
{
}

void capitalismCard::onUse(GameBoard* board, Player* player)
{
	EventCards::onUse(board, player);
	for (auto i = board->listOfPlayers.begin(); i != board->listOfPlayers.end() ; i++)
	{
		board->changeMoney(*i, -amount);
		board->changeMoney(player, amount);
	}
}
