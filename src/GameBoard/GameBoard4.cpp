#include "../../include/GameBoard4.h"


GameBoard4::GameBoard4(size_t grid_sizeX, size_t grid_sizeY)
{
	this->N = 4;
	this->cells_grid = vector<vector<GridCell>>(grid_sizeX, vector<GridCell>(grid_sizeY));
	this->nodes_grid = vector<vector<GridNode>>(grid_sizeX - 1, vector<GridNode>(grid_sizeY - 1, GridNode(2)));
}

size_t GameBoard4::getSidesTotal() const
{
	return (getSidesNodesSizeX() * 2 - 1) * getSidesNodesSizeY() - getSidesNodesSizeX();
}

void GameBoard4::draw() const
{
	vector<vector<GridCell>> cells_grid = this->getCellsGrid();
	vector<vector<GridNode>> nodes_grid = this->getNodesGrid();

	for (int i = 0; i < this->getSidesNodesSizeY(); ++i) {
		if (i < this->getCellsSizeY())
		{
			// drawing right side of Nodes
			for (int j = 0; j < this->getSidesNodesSizeX(); j++) {
				if (j == this->getCellsSizeX())
				{
					cout << "•" << endl;
					break;
				}

				cout << "•";

				if (nodes_grid[i][j].getDirection(0))
				{
					cout << "---";
				}
				else
				{
					cout << "   ";
				}
			}

			// drawing down side of Nodes and middle of Cell
			for (int j = 0; j < this->getSidesNodesSizeX(); j++) {
				if (j == this->getCellsSizeX())
				{
					if (nodes_grid[i][j].getDirection(1))
					{
						cout << "|";
					}
					else
					{
						cout << " ";
					}
					cout << endl;
					break;
				}

				if (nodes_grid[i][j].getDirection(1))
				{
					cout << "|";
				}
				else
				{
					cout << " ";
				}

				cout << " ";

				if (cells_grid[i][j].claimed) {
					cout << game->getPlayer(cells_grid[i][j].player_id_claimed_by)->getName();
				}
				else
				{
					cout << " ";
				}

				cout << " ";
			}
		}
		else
		{
			// drawing bottom of Grid
			for (int j = 0; j < this->getSidesNodesSizeX(); j++) {
				if (j == this->getCellsSizeX())
				{
					cout << "•" << endl;
					break;
				}

				cout << "•";

				if (nodes_grid[i][j].getDirection(0))
				{
					cout << "---";
				}
				else
				{
					cout << "   ";
				}
			}
			break;
		}
	}
}