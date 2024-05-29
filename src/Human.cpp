#include "../include/Human.h"
#include <iostream>

using namespace std;

void Human::makeMove(GameBoard board) 
{
	string input;
	cout << "Choose cell: ";
	cin >> input;
	cout << endl;
	choosen_cell = &board.flatten()[stoi(input)];
}

Human::Human(char name) : choosen_cell(nullptr)
{ 
}

Human::~Human()
{
}
