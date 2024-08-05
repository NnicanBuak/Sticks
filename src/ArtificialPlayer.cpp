#include "../include/ArtificialPlayer.h"


ArtificialPlayer::ArtificialPlayer(char name) :
    Player(name)
{};

Cell* ArtificialPlayer::requestDecision(Board board) const
{
    return nullptr;
}
