#include "../include/HumanPlayer.h"
#include "../include/Board.h"
#include <iostream>
#include <string>

using namespace std;

int HumanPlayer::getDecision(Board board) const
{
	string input;
	cout << "Choose cell: ";
	cin >> input;
	cout << endl;

	vector<Cell> cells = board.getFlattenGrid();
	int normalized_input = stoi(input);
	if (cells.size() < normalized_input <= 0)
	{
		return -1;
	}

	return normalized_input;
}