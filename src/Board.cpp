#include "../include/Board.h"
#include "../include/flatten.h"

using namespace std;


Board::Board(size_t size) :
	grid_cells(size, vector<Cell>(size)),
	grid_sides_nodes(size + 1, vector<SidesNode>(size + 1))
{};

Board::Board(size_t sizeX, size_t sizeY) :
	grid_cells(sizeX, vector<Cell>(sizeY)),
	grid_sides_nodes(sizeX + 1, vector<SidesNode>(sizeY + 1))
{};

vector<vector<Cell>> Board::getGridCells() const
{
	return grid_cells;
}

vector<Cell> Board::getFlattenGridCells() const
{
	return flatten(grid_cells);
}

vector<vector<SidesNode>> Board::getGridNodeSides() const
{
	return grid_sides_nodes;
}

vector<SidesNode> Board::getFlattenGridNodesSides() const
{
	return flatten(grid_sides_nodes);
}

bool Board::hasEmptyCells() const
{
	for (int i = 0; i < grid_cells.size(); i++)
	{
		for (int j = 0; j < grid_cells[i].size(); j++)
		{
			if (grid_cells[i][j].claimed == false)
			{
				return false;
			}
		}
	}
	return true;
}

size_t Board::getCellsSizeX() const {
	return grid_cells.empty() ? 0 : grid_cells.size();
}

size_t Board::getCellsSizeY() const {
	return grid_cells.empty() ? 0 : grid_cells[0].size();
}

size_t Board::getSidesNodesSizeX() const
{
	return grid_sides_nodes.empty() ? 0 : grid_sides_nodes.size();
}

size_t Board::getSidesNodesSizeY() const
{
	return grid_sides_nodes.empty() ? 0 : grid_sides_nodes[0].size();
}

size_t Board::getCellsTotal() const
{
	return getCellsSizeX() * getCellsSizeY();
}

size_t Board::getSidesNodesTotal() const
{
	return getSidesNodesSizeX() * getSidesNodesSizeY();
}

size_t Board::getSidesTotal() const
{
	return (getSidesNodesSizeX() * 2 - 1) * getSidesNodesSizeY() - getSidesNodesSizeX();
}