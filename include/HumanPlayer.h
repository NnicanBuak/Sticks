#pragma once
#include "Player.h"


class HumanPlayer :
    public Player 
{ 
public:
	explicit HumanPlayer(char name);
	~HumanPlayer() {};

	Cell* requestDecision(Board board) const override;
};

