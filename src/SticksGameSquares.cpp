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
	//
	vector<Cell> test = board.getFlattenGridCells();
	//
	vector<vector<Cell>> grid_cells = board.getGridCells();
	vector<vector<SidesNode>> grid_sides_nodes = board.getGridNodeSides();
	for (int i = 0; i < board.getSidesNodesSizeY(); ++i) {
		// top part
		for (int j = 0; j < board.getSidesNodesSizeX(); j++) {
			if (!grid_sides_nodes[i][j].right)
			{
				cout << "•   ";
			}
			else
			{
				cout << "•---";
			}
		}
		cout << "•" << endl;

		// middle part
		if (i < board.getCellsSizeY())
		{
			for (int j = 0; j < board.getSidesNodesSizeX(); j++) {
				if (!grid_sides_nodes[i][j].down)
				{
					cout << " ";
				}
				else
				{
					cout << "|";
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
			if (grid_sides_nodes[i][board.getCellsSizeX() - 1].down)
				cout << "|";
			cout << endl;
		}

		// bottom part
		for (int j = 0; j < board.getSidesNodesSizeX(); j++) {
			if (grid_sides_nodes[i][j].right)
			{
				cout << "•---";
			}
			else
			{
				cout << "•   ";
			}
		}
		cout << "•" << endl;
	}
}