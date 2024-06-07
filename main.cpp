#include "include/SticksGameSquares.h"
#include "include/Player.h"
#include "include/HumanPlayer.h"
#include "include/ArtificialPlayer.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{   
    //char name1, name2;
    //cout << "Enter P1 name: ";
    //cin >> name1;
    //cout << endl;
    //cout << "Enter P2 name: ";
    //cin >> name2;
    //cout << endl;
    SticksGameSquares game(size_t(3), vector<Player*>({ new HumanPlayer('A'), new ArtificialPlayer('B') }));
    game.drawBoard();
    return 0;
}