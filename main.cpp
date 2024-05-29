#include "src/SticksGameSquares.cpp"
#include "src/Player.cpp"
#include "src/Human.cpp"
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
    SticksGameSquares game(3, vector<Player>({ new Human('A'), new Human('B') }));
    game.drawBoard();
    return 0;
}