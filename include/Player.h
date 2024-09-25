#pragma once
#include "GameBoard.h"

using namespace std;


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
	virtual ~Player() = default;

	char getId() const;
	char getName() const;
	int getTotalCellsClaimed() const;

	virtual GridCell* requestDecision(GameBoard* board) const = 0;
};