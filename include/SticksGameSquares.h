#pragma once
#include "SticksGame.h"
#include "Player.h"


class SticksGameSquares :
    public SticksGame
{
public:
    explicit SticksGameSquares(size_t boardSize, vector<Player*> players);
    ~SticksGameSquares() {};

    void nextTurn() override;
    void drawBoard() const;
};