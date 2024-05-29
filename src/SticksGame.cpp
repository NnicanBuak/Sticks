#include "../include/SticksGame.h"

SticksGame::~SticksGame() {}

bool SticksGame::isGameOver() const
{
    return !winner->getName().empty();
}
