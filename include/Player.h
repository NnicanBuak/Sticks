#pragma once
#include "GameBoard.h"

using namespace std;

class Player
{
private:
	char name;
protected:
	int cells_claimed;
public:
	char getName() const;
	int getTotalCellsClaimed() const;
	virtual Cell* getDecision(GameBoard& board) = 0;
	Player(char name) : name(name), cells_claimed(0) {};
	virtual ~Player() {};
};