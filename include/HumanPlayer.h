#pragma once
#include "Player.h"


class HumanPlayer :
    public Player 
{ 
public:
	using Player::Player;

	GridCell* requestDecision(GameBoard* board) const override;
};

