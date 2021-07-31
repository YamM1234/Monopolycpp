#include "GoToJail.h"
#include "GameBoard.h"

void GoToJail::onUse(GameBoard* board, Player* player)
{
	EventCards::onUse(board, player);
	board->goToJail(player);
	board->canMoveAgain = false;
}
