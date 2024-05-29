#pragma once
#include "Player.h"
#include "GameBoard.h"

class Human :
    public Player 
{ 
public:
	Cell* getDecision(GameBoard& board) override;
	Human(char name);
	~Human();
};

