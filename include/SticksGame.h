#pragma once
#include "Board.h"
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
    int step = 1;
    int turn_player_id = players[0]->getId();
public:
    explicit SticksGame(size_t boardStructureType, size_t boardSize, vector<Player*> players);
    explicit SticksGame(size_t boardStructureType, size_t boardSizeX, size_t boardSizeY, vector<Player*> players);
    ~SticksGame() {};

    Player* getPlayer(int id) const;
    Player* getWinner() const;
    bool isGameOver() const;

    void start();

    virtual void nextTurn() = 0;
    virtual void drawBoard() const = 0;
};