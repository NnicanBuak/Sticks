#include "../../include/HumanPlayer.h"
#include <iostream>
#include <string>
#ifdef __has_include
#if __has_include(<ncurses.h>)
#define HAVE_NCURSES true
#include <ncurses.h>
#else
#define HAVE_NCURSES false
#endif
#endif


GridCell* HumanPlayer::requestDecision(GameBoard* board) const
{
	string input;
	cout << "Choose cell: ";
	cin >> input;
	cout << endl;

    vector<GridCell> cells = board->getCellsFlattenGrid();

    try {
        int normalized_input = stoi(input);
        if (normalized_input >= 0 && normalized_input < cells.size()) {
            return &(cells[normalized_input]);
        }
        else {
            cout << "Invalid input. Please choose a cell within range." << endl;
            return nullptr;
        }
    }
    catch (const invalid_argument& e) {
        cout << "Invalid input. Please enter a valid number." << endl;
        return nullptr;
    }
    catch (const out_of_range& e) {
        cout << "Invalid input. Number out of range." << endl;
        return nullptr;
    }
}