#include "../include/Human.h"
#include <iostream>
#include <string>

using namespace std;

Cell* Human::getDecision(GameBoard& board) 
{
	string input;
	cout << "Choose cell: ";
	cin >> input;
	cout << endl;

	vector<Cell> cells = board.flatten();
	int normalized_input = stoi(input);
	if (0 >= normalized_input > cells.size())
	{
		return;
	}

	return &cells[normalized_input - 1];
}

Human::Human(char name) : Player(name)
{ 
}

Human::~Human()
{
}
