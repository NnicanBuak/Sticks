#pragma once
#include "GameBoard3.h"
#include "GameBoard4.h"
#include "GameBoard6.h"
#include "Player.h"
#include <vector>

using namespace std;


class SticksGame
{
private:
    GameBoard* board;
    vector<Player*> players;
    int step = 1;
    int turn_player_id;
public:
    explicit SticksGame(int boardType, size_t boardSizeX, size_t boardSizeY, vector<Player*> players);
    ~SticksGame();

    Player* getPlayer(int id) const;
    Player* getWinner() const;
    bool isGameOver() const;

    void start();

    void nextTurn(); 
};