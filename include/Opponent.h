#pragma once
#include "Player.h"
#include "GameBoard.h"

class Opponent :
    public Player
{
public:
    Cell* getDecision(GameBoard board) override;
    Opponent(char name) : Player(name) {}
    ~Opponent() {}
};

