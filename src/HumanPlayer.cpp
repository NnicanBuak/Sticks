#include "../include/HumanPlayer.h"
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

using namespace std;

Cell* HumanPlayer::getDecision(Board board) const
{
	string input;
	cout << "Choose cell: ";
	cin >> input;
	cout << endl;

    vector<Cell> cells = board.getFlattenGrid();

    try {
        int normalized_input = stoi(input);
        if (normalized_input >= 0 && normalized_input < cells.size()) {
            return &cells[normalized_input];
        }
        else {
            cout << "Invalid input. Please choose a cell within range." << endl;
            return nullptr;
        }
    }
    catch (const std::invalid_argument& e) {
        cout << "Invalid input. Please enter a valid number." << endl;
        return nullptr;
    }
    catch (const std::out_of_range& e) {
        cout << "Invalid input. Number out of range." << endl;
        return nullptr;
    }
}