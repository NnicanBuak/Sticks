#pragma once
#include "Player.h"
#include <vector>
#include <map>

using namespace std;

struct Cell {
    size_t num_sides;
    map<int, Player*> sides_status;
    Player* claimed_by;

    Cell(size_t num_sides) : num_sides(num_sides), claimed_by(nullptr) {};
    ~Cell() {};
};

struct GameBoard {
    vector<vector<Cell>> grid;

    vector<Cell> flatten() const;
    int getTotalCells() const;
    size_t getSize() const;
    size_t getCellSides() const;
    GameBoard(size_t size, size_t cell_sides) : grid(size, vector<Cell>(size)) {};
    ~GameBoard() {};
};