#pragma once
#include "SticksGame.h"
#include "Player.h"

class SticksGameSquares :
    public SticksGame
{
public:
    void nextTurn() override;
    void drawBoard() const;
    SticksGameSquares(size_t boardSize, vector<Player*> players) : SticksGame(4, boardSize, players) {};
    ~SticksGameSquares() {};
};