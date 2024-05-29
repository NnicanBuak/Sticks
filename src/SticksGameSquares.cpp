#include "../include/SticksGameSquares.h" 
#include <stdlib.h>

using namespace std;

void SticksGameSquares::drawBoard()  const
{
    for (int i = 0; i < board.getSize(); ++i) {
        // Вывод верхней части клетки
        for (int j = 0; j < board.getSize(); ++j) {
            cout << "•---";
        }
        cout << "•" << endl;

        // Вывод середины клетки и информации о захвате
        for (int j = 0; j < board.getSize(); j++) {
            cout << "| ";
            if (board.grid[i][j].claimed_by != nullptr) {
                cout << board.grid[i][j].claimed_by->getName();
            }
            else {
                cout << " "; 
            }
            cout << " ";
        }
        cout << "|" << endl;

        // Вывод нижней части клетки
        for (int j = 0; j < board.getSize(); j++) {
            cout << "•---";
        }
        cout << "•" << endl;
    }
}


Player* SticksGameSquares::getWinner() const {
    int maxCells = -1;
    Player* winner = nullptr;
    for (auto player : players) { 
        if (player.getTotalCellsClaimed() > maxCells) {
            maxCells = player.getTotalCellsClaimed();
            winner = &player;
        }
    }
     
    if (winner != nullptr && maxCells > board.getTotalCells() / 2) {
        cout << "Player " << winner->getName() << " wins by having the most claimed cells! (" << winner->getTotalCellsClaimed() << ")" << endl;
        return winner;
    } 
     
    cout << "The game ends in a draw! All cells are claimed." << endl;
    return winner;
}
