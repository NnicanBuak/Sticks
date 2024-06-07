#include "../include/SticksGame.h"

bool SticksGame::isGameOver() const
{
    return winner->getName() != '\0'; 
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