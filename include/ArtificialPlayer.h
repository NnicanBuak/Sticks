#pragma once
#include "Player.h"


class ArtificialPlayer :
    public Player
{
public:
    using Player::Player;

    GridCell* requestDecision(GameBoard* board) const override;
};

