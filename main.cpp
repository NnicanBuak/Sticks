#include "include/SticksGame.h"
#include "include/Player.h"
#include "include/HumanPlayer.h"
#include "include/ArtificialPlayer.h"
#include <vector>
#include <iostream>
#include <memory>

using namespace std;


int main()
{  
	/*char name1, name2;
	cout << "Enter P1 name: ";
	cin >> name1;
	cout << endl;
	cout << "Enter P2 name: ";
	cin >> name2;
	cout << endl;*/ 

	vector<Player*> players;
	players.push_back(new HumanPlayer('A'));
	players.push_back(new ArtificialPlayer('B'));

	SticksGame game(4, 2, 2, move(players));

	game.start();
    return 0;
}