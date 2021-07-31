#pragma once
#include <string>

class GameBoard;
class Player;

class Tile
{
public:
	const std::string name;
public:
	Tile();
	Tile(std::string name);
	virtual void onLand(GameBoard* board, Player* player);
};
