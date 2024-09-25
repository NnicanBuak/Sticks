#include "../include/SticksGame.h"


SticksGame::SticksGame(int boardType, size_t boardSizeX, size_t boardSizeY, vector<Player*> players) :
	players(players)
{
	turn_player_id = players[0]->getId();

	switch (boardType) {
	case 3:
		board = new GameBoard3(boardSizeX, boardSizeY);
		break;
	case 4:
		board = new GameBoard4(boardSizeX, boardSizeY);
		break;
	case 6:
		board = new GameBoard6(boardSizeX, boardSizeY);
		break;
	default:
		throw invalid_argument("Invalid board type");
	}
};

SticksGame::~SticksGame()
{
	for (Player* player : players) {
		delete player;
	}
};

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
	if (winner != nullptr && maxCells > board->getCellsTotal() / 2) {
		return winner;
	}

	return winner;
}

bool SticksGame::isGameOver() const
{
	return !board->hasEmptyCells();
}

void SticksGame::start()
{
	board->draw();
	while (getWinner() == nullptr)
	{
		nextTurn();
	}
}

void SticksGame::nextTurn()
{
	GridCell* move = getPlayer(turn_player_id)->requestDecision(board);
}

