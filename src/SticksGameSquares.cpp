#include "../include/SticksGameSquares.h" 
#include <stdlib.h>

using namespace std;


SticksGameSquares::SticksGameSquares(size_t boardSize, vector<Player*> players) :
	SticksGame(4, boardSize, players)
{};

void SticksGameSquares::nextTurn()
{
	Cell* move = getPlayer(turn_player_id)->requestDecision(board);
}

void SticksGameSquares::drawBoard() const
{
	vector<vector<Cell>> grid_cells = board.getGridCells();
	vector<vector<SidesNode>> grid_sides_nodes = board.getGridNodeSides();
	for (int i = 0; i < board.getSidesNodesSizeY(); ++i) {
		if (i < board.getCellsSizeY())
		{
			// drawing right side of Nodes
			for (int j = 0; j < board.getSidesNodesSizeX(); j++) {
				if (j == board.getCellsSizeX())
				{
					cout << "•" << endl;
					break;
				}

				cout << "•";

				if (grid_sides_nodes[i][j].right)
				{
					cout << "---";
				}
				else
				{
					cout << "   ";
				}
			}

			// drawing down side of Nodes and middle of Cell
			for (int j = 0; j < board.getSidesNodesSizeX(); j++) {
				if (j == board.getCellsSizeX())
				{
					if (grid_sides_nodes[i][j].down)
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

				if (grid_sides_nodes[i][j].down)
				{
					cout << "|";
				}
				else
				{
					cout << " ";
				}

				cout << " ";

				if (grid_cells[i][j].claimed) {
					cout << getPlayer(grid_cells[i][j].player_id_claimed_by)->getName();
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
			for (int j = 0; j < board.getSidesNodesSizeX(); j++) {
				if (j == board.getCellsSizeX())
				{
					cout << "•" << endl;
					break;
				}

				cout << "•";

				if (grid_sides_nodes[i][j].right)
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