#include "../include/SticksGameSquares.h" 
#include <stdlib.h>

using namespace std;

void SticksGameSquares::drawBoard()  const
{
    for (int i = 0; i < board.getSizeX(); ++i) {
        // top part
        for (int j = 0; j < board.getSizeX(); ++j) {
            cout << "•---";
        }
        cout << "•" << endl;

        // middle part
        for (int j = 0; j < board.getSizeX(); j++) {
            cout << "| ";
            if (board.getGrid()[i][j].player_id_claimed_by != -1) {
                cout << getPlayer(board.getGrid()[i][j].player_id_claimed_by)->getName();
            }
            else {
                cout << " "; 
            }
            cout << " ";
        }
        cout << "|" << endl;

        // bottom part
        if (i == board.getSizeX() - 1)
        {
            for (int j = 0; j < board.getSizeX(); j++) {
                if (board.getGrid()[i][j].player_id_claimed_by == -1 or board.getGrid()[i][j].getSideStatus(2))
                    cout << "•---";
            }
            cout << "•" << endl;
        }
    }
}

Player* SticksGameSquares::getWinner() const {
    int maxCells = -1;
    Player* winner = nullptr;
    for (auto player : players) { 
        if (player->getTotalCellsClaimed() > maxCells) {
            maxCells = player->getTotalCellsClaimed();
            winner = player;
        }
    }
     
    if (winner != nullptr && maxCells > board.getTotalCells() / 2) {
        cout << "Player " << winner->getName() << " wins by having the most claimed cells! (" << winner->getTotalCellsClaimed() << ")" << endl;
        return winner;
    } 
     
    cout << "The game ends in a draw! All cells are claimed." << endl;
    return winner;
}

Cell* SticksGameSquares::makeMove(Board board)
{
    return nullptr;
}