#include "../include/Board.h"
#include "../include/flatten.h"

using namespace std;


Board::Board(size_t size) :
	grid_cells(size, vector<Cell>(size)),
	flatten_grid_cells(size* size),
	grid_sides_nodes(size + 1, vector<SidesNode>(size)),
	flatten_grid_sides_nodes((size + 1)* size)
{

	// Initialize grid_cells and flatten_grid_cells
	for (size_t i = 0; i < size; ++i) {
		for (size_t j = 0; j < size; ++j) {
			grid_cells[i][j] = Cell();
			flatten_grid_cells[i * size + j] = grid_cells[i][j];
		}
	}

	// Initialize grid_nodes_sides and flatten_grid_nodes_sides
	for (size_t i = 0; i <= size; ++i) {
		for (size_t j = 0; j <= size; ++j) {
			grid_sides_nodes[i][j] = SidesNode();
			flatten_grid_sides_nodes[i * size + j] = grid_sides_nodes[i][j];
		}
	}
};

Board::Board(size_t sizeX, size_t sizeY) :
	grid_cells(sizeX, vector<Cell>(sizeY)),
	flatten_grid_cells(sizeX* sizeY),
	grid_sides_nodes(sizeX + 1, vector<SidesNode>(sizeY + 1)),
	flatten_grid_sides_nodes((sizeX + 1)* (sizeY + 1))
{
	// Initialize grid_cells and flatten_grid_cells
	for (size_t i = 0; i < sizeX; ++i) {
		for (size_t j = 0; j < sizeY; ++j) {
			grid_cells[i][j] = Cell();
			flatten_grid_cells[i * sizeY + j] = grid_cells[i][j];
		}
	}

	// Initialize grid_nodes_sides and flatten_grid_nodes_sides
	for (size_t i = 0; i <= sizeX; ++i) {
		for (size_t j = 0; j <= sizeY; ++j) {
			grid_sides_nodes[i][j] = SidesNode();
			flatten_grid_sides_nodes[i * (sizeY + 1) + j] = grid_sides_nodes[i][j];
		}
	}
}

vector<vector<Cell>> Board::getGridCells() const
{
	return grid_cells;
}

vector<Cell> Board::getFlattenGridCells() const
{
	if (flatten_grid_cells.empty())
	{
		return flatten_grid_cells;
	}

	return flatten(grid_cells);
}

vector<vector<SidesNode>> Board::getGridNodeSides() const
{
	return grid_sides_nodes;
}

vector<SidesNode> Board::getFlattenGridNodesSides() const
{
	if (flatten_grid_sides_nodes.empty())
	{
		return flatten_grid_sides_nodes;
	}

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
	if (flatten_grid_cells.size() != 0)
	{
		return flatten_grid_cells.size();
	}
	return getCellsSizeX() * getCellsSizeY();
}

size_t Board::getSidesNodesTotal() const
{
	if (flatten_grid_sides_nodes.size() != 0)
	{
		return flatten_grid_sides_nodes.size();
	}
	return getSidesNodesSizeX() * getSidesNodesSizeY();
}

size_t Board::getSidesTotal() const
{
	return (getSidesNodesSizeX() * 2 - 1) * getSidesNodesSizeY() - getSidesNodesSizeX();
}