#include "GoToJailTile.h"
#include "GameBoard.h"

GoToJailTile::GoToJailTile(std::string name)
	:Event::Event(name)
{
}

void GoToJailTile::onLand(GameBoard* board, Player* player)
{
	board->goToJail(player);
	board->canMoveAgain = false;
}
