#include "EventCards.h"
#include <iostream>

using namespace std;

EventCards::EventCards(std::string message)
	:message{ message }
{
}

void EventCards::onUse(GameBoard* board, Player* player)
{
	cout << message << endl;
}
