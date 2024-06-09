#pragma once
#include "Cell.h"
#include <vector>
#include <map>

using namespace std;

class Board {
private:
    vector<vector<Cell>> grid;
public:
    //vector<vector<Cell*>> getGrid() const;
    vector<Cell*> getFlattenGrid() const;
    bool hasEmptyCells() const;
    size_t getSizeX() const;
    size_t getSizeY() const;
    size_t getTotalCells() const;
    size_t getCellSides() const;

    Board(size_t cellSides, size_t size) : grid(size, vector<Cell>(size, Cell(cellSides))) {};
    Board(size_t cellSides, size_t sizeX, size_t sizeY) : grid(sizeX, vector<Cell>(sizeY, Cell(cellSides))) {};
    ~Board() {};
};