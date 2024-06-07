#pragma once
#include "SticksGame.h"
#include "Player.h"

class SticksGameSquares :
    public SticksGame
{
private:
    pair<int, Player*> turn;
public:
    Player* getWinner() const;
    Cell* makeMove(Board board) override;
    void drawBoard() const;
    SticksGameSquares(size_t boardSize, vector<Player*> players) : SticksGame(4, boardSize, players) {};
    ~SticksGameSquares() {};
};