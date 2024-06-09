#include "../include/SticksGame.h"

void SticksGame::start()
{
    drawBoard();
    while (getWinner() == nullptr)
    {
        nextTurn();
    }
}

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
    if (winner != nullptr && maxCells > board.getTotalCells() / 2) {
        return winner;
    }

    return winner;
}

bool SticksGame::isGameOver() const
{
    return !board.hasEmptyCells();
}

