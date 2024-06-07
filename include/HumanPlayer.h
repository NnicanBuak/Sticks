#pragma once
#include "Player.h"

class HumanPlayer :
    public Player 
{ 
public:
	int getDecision(Board board) const override;

	HumanPlayer(char name) : Player(name) {};
	~HumanPlayer() {};
};

