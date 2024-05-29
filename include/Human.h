#pragma once
#include "Player.h"
#include "GameBoard.h"

class Human :
    public Player
{
private:
	Cell* choosen_cell;
public:
	void makeMove(GameBoard board) override;
	Human(char name);
	~Human();
};

