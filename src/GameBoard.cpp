#include "../include/GameBoard.h"

Cell::Cell(size_t num_sides)
{
    for (int i = 0; i < num_sides; ++i) {
        side_status[i] = false;
    }
}

GameBoard::GameBoard(size_t size, size_t cell_size)
{
    // Initialization 2d matrix of Cells 
    grid.resize(size, vector<Cell>(size, Cell(cell_size)));
}

vector<Cell> GameBoard::flatten() const
{
    vector<Cell> flattened;

    for (const auto& row : grid) {
        for (const auto& cell : row) {
            flattened.push_back(cell);
        }
    }

    return flattened;
}


