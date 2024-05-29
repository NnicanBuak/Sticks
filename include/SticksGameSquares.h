#pragma once
#include "SticksGame.h"

class SticksGameSquares :
    public SticksGame
{
public:
    void drawBoard() const;
    bool hasWinner() const;
    SticksGameSquares(size_t boardSize, vector<Player> players) : SticksGame(4, boardSize, players) {}
    ~SticksGameSquares() {}
};