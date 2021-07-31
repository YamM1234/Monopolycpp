#include "LuxuryTax.h"
#include <iostream>
#include "GameBoard.h"

using namespace std;

LuxuryTax::LuxuryTax(std::string name)
	:Event::Event(name)
{
}

void LuxuryTax::onLand(GameBoard* board, Player* player)
{
	cout << "Collecting $75 from " << player->name << endl;
	board->changeMoney(player, -75);
}

