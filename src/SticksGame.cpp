#include "../include/SticksGame.h"


void SticksGame::start()
{
	drawBoard();
	while (getWinner() == nullptr)
	{
		nextTurn();
	}
}

SticksGame::SticksGame(size_t boardStructureType, size_t boardSize, vector<Player*> players) :
	board(boardSize),
	board_structure_type(boardStructureType),
	players(players)
{}

SticksGame::SticksGame(size_t boardStructureType, size_t boardSizeX, size_t boardSizeY, vector<Player*> players) :
	board(boardSizeX, boardSizeY),
	board_structure_type(boardStructureType),
	players(players)
{};

Player* SticksGame::getPlayer(int id) const
{
	for (auto player : players)
	{
		if (player->getId() == id)
			return player;
	}
	return nullptr;
}

Player* SticksGame::getWinner() const {
	// Find Player with max claimed cells
	int maxCells = -1;
	Player* winner = nullptr;
	for (auto player : players) {
		if (player->getTotalCellsClaimed() > maxCells) {
			maxCells = player->getTotalCellsClaimed();
			winner = player;
		}
	}

	// Check winning condition
	if (winner != nullptr && maxCells > board.getCellsTotal() / 2) {
		return winner;
	}

	return winner;
}

bool SticksGame::isGameOver() const
{
	return !board.hasEmptyCells();
}

