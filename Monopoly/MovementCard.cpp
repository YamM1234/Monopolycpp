#include "MovementCard.h"
#include "GameBoard.h"

MovementCard::MovementCard(std::string message, int destination)
	:EventCards::EventCards(message),destination{destination}
{
}

void MovementCard::onUse(GameBoard* board, Player* player)
{
	EventCards::onUse(board, player);
	if (player->currPos > destination) {
		board->changeMoney(player, 200);
	}
	player->currPos = destination;
}
