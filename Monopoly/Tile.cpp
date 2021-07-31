#include "Tile.h"
#include <iostream>
#include "Player.h"

using namespace std;

Tile::Tile()
{
}

Tile::Tile(std::string name)
	:name{name}
{
}

void Tile::onLand(GameBoard* board, Player* player)
{
	cout << player->name << " landed on " << this->name << endl;
}
