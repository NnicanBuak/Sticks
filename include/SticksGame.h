#pragma once
#include "GameBoard.h"
#include "Player.h"
#include <iostream>
#include <vector>

using namespace std;

class SticksGame
{
private:
    size_t board_structure_type;
protected:
    GameBoard board;
    vector<Player> players;
public:
    bool isGameOver() const;
    virtual void drawBoard() const = 0;
    virtual Player* getWinner() const = 0;
    SticksGame(size_t board_structure_type, size_t boardSize, vector<Player> players) : board(boardSize, board_structure_type), board_structure_type(board_structure_type), players(players), winner(nullptr) {};
    virtual ~SticksGame() {};
};