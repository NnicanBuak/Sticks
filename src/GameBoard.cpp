#include "../include/GameBoard.h"

Cell::Cell(size_t num_sides)
{
    for (int i = 0; i < num_sides; ++i) {
        sides_status[i] = false;
    }
}

GameBoard::GameBoard(size_t size, size_t cell_sides)
{ 
    grid.resize(size, vector<Cell>(size, Cell(cell_sides)));
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

size_t GameBoard::getSize() const {
    return grid.size() * grid[0].size();
}

size_t GameBoard::getCellSides() const {
    return grid[0][0].num_sides;
}

int GameBoard::getTotalCells() const
{
    return getSize() * getSize();
}

