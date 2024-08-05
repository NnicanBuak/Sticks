#pragma once
#include "Player.h"


class ArtificialPlayer :
    public Player
{
public:
    explicit ArtificialPlayer(char name);
    ~ArtificialPlayer() {};

    Cell* requestDecision(Board board) const override;
};

