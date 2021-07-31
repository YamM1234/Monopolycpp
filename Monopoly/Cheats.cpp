#include "Cheats.h"
#include "Player.h"

void addMoneyCheat(Player* player, int amount)
{
	player->balance += amount;
}

void teleportCheat(Player* player, int pos)
{
	player->currPos = pos;
}

