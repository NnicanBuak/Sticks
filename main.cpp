#include "SticksGameSquares.h"
#include "Player.h"
#include <vector>
#include <iostream>

using namespace std;

int main()
{   
    string name1, name2;
    cout << "Enter P1 name: ";
    cin >> name1;
    cout << endl;
    cout << "Enter P2 name: ";
    cin >> name2;
    cout << endl;
    SticksGameSquares game(3, vector<Player>({ Player(name1), Player(name2)}));
    game.drawBoard();
    return 0;
}