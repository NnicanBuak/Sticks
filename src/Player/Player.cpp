#include "../../include/Player.h"


int Player::current_id = -1;

Player::Player(char name) :
	id(current_id++),
	name(name)
{
}

char Player::getId() const
{
	return id;
}

char Player::getName() const
{
	return name;
}

int Player::getTotalCellsClaimed() const
{
	return cells_claimed;
}