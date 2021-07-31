#include "Chance.h"
#include <random>
#include <time.h>
#include "GameBoard.h"
#include "EventCards.h"

using namespace std;

Chance::Chance(std::string name)
	: Event::Event(name)
{
}

Chance::~Chance()
{
	for (size_t i = 0; i < cards.size(); i++)
	{
		delete cards[i];
	}
}

void Chance::onLand(GameBoard* board, Player* player)
{
	Tile::onLand(board, player);
	static default_random_engine engine{ static_cast<unsigned int>(time(0)) };
	static uniform_int_distribution<size_t> randAccesor{ 1, cards.size()};
	board->canMoveAgain = true;
	cards[randAccesor(engine) - 1]->onUse(board, player);
}
