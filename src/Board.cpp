#include "../include/Board.h"

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

bool Board::hasEmptyCells() const
{
    for (int i = 0; i < getSizeX(); i++)
    {
        for (int j = 0; j < getSizeY(); j++)
            for (int k = 0; k < grid[i][j].getNumSides(); k++)
            {
                if (grid[i][j].getSideStatus(k) == -1)
                    return false;
            }
    }
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
