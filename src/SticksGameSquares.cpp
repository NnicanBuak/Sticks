#include "../include/SticksGameSquares.h" 
#include <stdlib.h>

using namespace std;

void SticksGameSquares::drawBoard() const
{
    for (int i = 0; i < board.size; ++i) {
        for (int j = 0; j < board.size; ++j) {
            // Выводим точку для каждого квадрата
            cout << ". ";
        }
        cout << endl;
    }
}

bool SticksGameSquares::hasWinner() const
{
	return false;
}
