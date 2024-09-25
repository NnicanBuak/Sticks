#include "../../include/GameBoard3.h"


GameBoard3::GameBoard3(size_t grid_sizeX, size_t grid_sizeY)
{
	this->N = 3;
	this->cells_grid = vector<vector<GridCell>>(grid_sizeX, vector<GridCell>(grid_sizeY));
	this->nodes_grid = vector<vector<GridNode>>(grid_sizeX - 1, vector<GridNode>(grid_sizeY - 1, GridNode(2)));
}

size_t GameBoard3::getSidesTotal() const
{
	return (getSidesNodesSizeX() * 2 - 1) * getSidesNodesSizeY() - getSidesNodesSizeX();
}

void GameBoard3::draw() const
{
}
