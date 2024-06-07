#pragma once
#include "Cell.h"
#include <vector>
#include <map>

using namespace std;

class Board {
private:
    vector<vector<Cell>> grid;
public:
    vector<vector<Cell>> getGrid() const;
    vector<Cell> getFlattenGrid() const;
    size_t getSizeX() const;
    size_t getSizeY() const;
    size_t getTotalCells() const;
    size_t getCellSides() const;

    Board(size_t size, size_t cell_sides) : grid(size, vector<Cell>(size))
    {
        grid.resize(size, vector<Cell>(size, Cell(cell_sides)));
    }
    ~Board() {};
};