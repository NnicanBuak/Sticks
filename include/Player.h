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
	explicit Player(char name);
	~Player() {};

	char getId() const;
	char getName() const;
	int getTotalCellsClaimed() const;

	virtual Cell* requestDecision(Board board) const = 0;
};