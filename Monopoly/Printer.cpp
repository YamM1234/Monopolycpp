#include "Printer.h"
#include <sstream>
#include "GameBoard.h"
#include <iostream>


using namespace std;
const size_t WIDTH = 20;
const size_t HEIGHT = 10;
const size_t TILE_BORDER_HEIGHT = HEIGHT + 1;
const size_t TILE_COUNT = 40;
const size_t BOARD_WIDTH = WIDTH + 2;
const size_t BOARD_HEIGHT = TILE_BORDER_HEIGHT * TILE_COUNT + 1;

array<array<char, WIDTH>, HEIGHT> * printTile(Tile * a)
{
	array<array<char, WIDTH>, HEIGHT> *out = new array<array<char, WIDTH>, HEIGHT>;
	for (size_t j = 0; j < HEIGHT; j++) {
		for (size_t i = 0; i < WIDTH; i++) {
			(*out)[j][i] = ' ';
		}
	}
	stringstream ss;
	ss << a->name;
	string in;
	string names[3]{"", "", ""};
	for (size_t i = 0; ss >> in && i < 3; i++)
	{
		names[i] = in;
	}
	if (names[2] != "") {
		names[0] = names[0] + " " + names[1];
		names[1] = names[2];
	}
	for (size_t i = 0; i < 2; i++)
	{
		copy(names[i].begin(), names[i].end(), (*out)[i].begin());
	}
	return out;
}

void printBoard(GameBoard* a) {
	array<array<char, BOARD_WIDTH>, BOARD_HEIGHT> *board = new array<array<char, BOARD_WIDTH>, BOARD_HEIGHT>;
	for (size_t j = 0; j < BOARD_HEIGHT; j++) {
		for (size_t i = 0; i < BOARD_WIDTH; i++) {
			(*board)[j][i] = ' ';
		}
	}
	for (size_t i = 0; i < BOARD_HEIGHT; i++)
	{
		(*board)[i][0] = '|';
		(*board)[i][BOARD_WIDTH - 1] = '|';
	}
	for (size_t j = 0; j < TILE_COUNT + 1; j++) 
	{
		for (size_t i = 0; i < BOARD_WIDTH; i++)
			(*board)[j * TILE_BORDER_HEIGHT][i] = '-';
	
	}
	for (size_t i = 0; i < TILE_COUNT; i++)
	{
		array<array<char, WIDTH>, HEIGHT> *tile = printTile(a->board[i]);
		for (size_t j = 0; j < HEIGHT; j++)
		{
			copy((*tile)[j].begin(), (*tile)[j].end(), ++(*board)[i*TILE_BORDER_HEIGHT+1+j].begin());
		}
		delete tile;
	}
	for (size_t i = 0; i < a->listOfPlayers.size(); i++)
	{
		if (a->listOfPlayers[i]->name.size() > WIDTH) {
			copy(a->listOfPlayers[i]->name.begin(), a->listOfPlayers[i]->name.begin() + WIDTH,
				++(*board)[(a->listOfPlayers[i]->currPos) * TILE_BORDER_HEIGHT + 3 + i].begin()); //git gud son!!
		}
		else {
			copy(a->listOfPlayers[i]->name.begin(), a->listOfPlayers[i]->name.end(),
				++(*board)[(a->listOfPlayers[i]->currPos) * TILE_BORDER_HEIGHT + 3 + i].begin());
		}
	}
	for (size_t i = 0; i < BOARD_HEIGHT; i++)
	{
		cout << string((*board)[i].begin(), (*board)[i].end()) << endl;
	}
	delete board;
}
