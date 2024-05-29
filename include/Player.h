#pragma once

using namespace std;

class Player
{
private:
	char name;
protected:
	int cells_claimed;
public:
	char getName() const;
	virtual void makeMove(GameBoard board) = 0;
	Player(char name) : name(name), cells_claimed(0) {};
	virtual ~Player() {};
};