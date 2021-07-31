#include "RelativeMovementCard.h"
#include "GameBoard.h"

RelativeMovementCard::RelativeMovementCard(std::string message, int move)
	: EventCards::EventCards(message), move{ move }
{
}

void RelativeMovementCard::onUse(GameBoard* board, Player* player)
{
	EventCards::onUse(board, player);
	player->currPos += move;
}
