#include "../include/Board.h"
#include "../include/Cell.h"

using namespace std;

vector<vector<Cell>> Board::getGrid() const
{
    return grid;
}

vector<Cell> Board::getFlattenGrid() const
{
    vector<Cell> flattened;

    for (const auto& row : grid) {
        for (const auto& cell : row) {
            flattened.push_back(cell);
        }
    }

    return flattened;
}

size_t Board::getSizeX() const {
    return grid.size();
}

size_t Board::getSizeY() const {
    return grid[0].size();
}

size_t Board::getCellSides() const {
    return grid[0][0].getNumSides();
}

size_t Board::getTotalCells() const
{
    return getSizeX() * getSizeY();
}
