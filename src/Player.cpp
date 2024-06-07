#include "../include/Player.h"
#include <iostream>

using namespace std;

int Player::current_id = 0;

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

