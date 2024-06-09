#pragma once
#include "Player.h"

class HumanPlayer :
    public Player 
{ 
public:
	void getDecision(Board board) const override;

	HumanPlayer(char name) : Player(name) {};
	~HumanPlayer() {};
};

