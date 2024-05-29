#pragma once
#include "SticksGame.h"

class SticksGameSquares :
    public SticksGame
{
public:
    void drawBoard() const;
    Player* getWinner() const;
    SticksGameSquares(size_t boardSize, vector<Player> players) : SticksGame(4, boardSize, players) {}
    ~SticksGameSquares() {}
};