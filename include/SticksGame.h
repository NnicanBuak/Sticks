#pragma once
#include "Board.h"
#include "Cell.h"
#include "Player.h"
#include <iostream>
#include <vector>

using namespace std;

class SticksGame
{
private:
    size_t board_structure_type;
protected:
    Board board;
    vector<Player*> players;
    Player* winner;
public:
    Player* getPlayer(int id) const;
    bool isGameOver() const;
    virtual Player* getWinner() const = 0;
    virtual Cell* makeMove(Board board) = 0;
    virtual void drawBoard() const = 0;
    SticksGame(size_t board_structure_type, size_t boardSize, vector<Player*> players) : board(boardSize, board_structure_type), board_structure_type(board_structure_type), players(players), winner(nullptr) {};
    ~SticksGame() {};
};