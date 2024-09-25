#include "../../include/GameBoard.h"


GameBoard::GameBoard(SticksGame* game) :
	game(game)
{
	cells_grid = vector<vector<GridCell>>(grid_sizeX, vector<GridCell>(grid_sizeY));
}

vector<vector<GridCell>> GameBoard::getCellsGrid() const
{
	return cells_grid;
}

vector<vector<GridNode>> GameBoard::getNodesGrid() const
{
	return nodes_grid;
}

vector<GridCell> GameBoard::getCellsFlattenGrid() const
{
	return flatten(cells_grid);
}

vector<GridNode> GameBoard::getNodesFlattenGrid() const
{
	return flatten<GridNode>(nodes_grid);
}

size_t GameBoard::getCellsSizeX() const {
	return cells_grid.empty() ? 0 : cells_grid.size();
}

size_t GameBoard::getCellsSizeY() const {
	return cells_grid.empty() ? 0 : cells_grid[0].size();
}

size_t GameBoard::getSidesNodesSizeX() const
{
	return nodes_grid.empty() ? 0 : nodes_grid.size();
}

size_t GameBoard::getSidesNodesSizeY() const
{
	return nodes_grid.empty() ? 0 : nodes_grid[0].size();
}

size_t GameBoard::getCellsTotal() const
{
	return getCellsSizeX() * getCellsSizeY();
}

size_t GameBoard::getSidesNodesTotal() const
{
	return getSidesNodesSizeX() * getSidesNodesSizeY();
}

bool GameBoard::hasEmptyCells() const
{
	for (const auto cell_row : cells_grid)
	{
		for (const auto cell : cell_row)
		{

			if (cell.claimed == false)
				return true;
		}
	}
	return false;
}
