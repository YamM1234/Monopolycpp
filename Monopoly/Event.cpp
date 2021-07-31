#include <iostream>
#include <random>
#include <time.h>
#include "Event.h"

using namespace std;


Event::Event(std::string name)
	: Tile::Tile(name) 
{
}

void Event::onLand(GameBoard* board, Player* player)
{
	Tile::onLand(board, player);
}
