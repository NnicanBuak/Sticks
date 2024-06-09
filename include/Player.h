#pragma once
#include "Board.h"

class Player
{
private:
	static int current_id;
protected:
	int id;
	char name;
	int cells_claimed = 0;
public:
	char getId() const;
	char getName() const;
	int getTotalCellsClaimed() const;

	virtual void getDecision(Board board) const = 0;
	
	Player(char name) : id(current_id++), name(name) {};
	~Player() {};
};