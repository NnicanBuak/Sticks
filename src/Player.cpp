#include "../include/Player.h"

using namespace std;

int Player::current_id = -1;

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

