#pragma once
#include "GameStructures.h"
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
    Player* winner;
public:
    bool isGameOver() const;
    virtual void drawBoard() const = 0;
    virtual bool hasWinner() const = 0;
    SticksGame(size_t board_structure_type, size_t boardSize, vector<Player> players) : board(boardSize, board_structure_type), board_structure_type(board_structure_type), players(players), winner(nullptr) {};
    virtual ~SticksGame() {};
};