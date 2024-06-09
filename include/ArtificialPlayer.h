#pragma once
#include "Player.h"

class ArtificialPlayer :
    public Player
{
public:
    void getDecision(Board board) const override;

    ArtificialPlayer(char name) : Player(name) {}
    ~ArtificialPlayer() {}
};

