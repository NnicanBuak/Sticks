#include "../include/SticksGameSquares.h" 
#include <stdlib.h>

using namespace std;

void SticksGameSquares::drawBoard()  const
{
    for (int i = 0; i < board.getSizeY(); ++i) {
        // top part
        for (int j = 0; j < board.getSizeX(); j++) {
            if (board.getGrid()[i][j].player_id_claimed_by == -1 or !board.getGrid()[i][j].getSideStatus(0))
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
        for (int j = 0; j < board.getSizeX(); j++) {
            if (board.getGrid()[i][j].player_id_claimed_by == -1 or !board.getGrid()[i][j].getSideStatus(3))
            {
                cout << " ";
            }
            else
            {
                cout << "|";
            }
            cout << " ";
            if (board.getGrid()[i][j].player_id_claimed_by == -1) {
                cout << " ";
            }
            else 
            {
                cout << getPlayer(board.getGrid()[i][j].player_id_claimed_by)->getName();
            }
            cout << " ";
        }
        if (board.getGrid()[i][board.getSizeX() - 1].getSideStatus(1))
            cout << "|";
        cout << endl;

        // bottom part
        if (i == board.getSizeX() - 1)
        {
            for (int j = 0; j < board.getSizeX(); j++) {
                if (board.getGrid()[i][j].player_id_claimed_by == -1 or !board.getGrid()[i][j].getSideStatus(2))
                {
                    cout << "•   ";
                }
                else
                {
                    cout << "•---";
                }
            }
            cout << "•" << endl;
        }
    }
}

Cell* SticksGameSquares::nextTurn()
{
    int move = getPlayer(turn_player_id)->getDecision(board);
    return board.getFlattenGrid();
}