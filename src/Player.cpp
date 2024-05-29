#include "../include/Player.h"
#include <iostream>

using namespace std;

char Player::getName() const
{
	return name;
}
int Player::getTotalCellsClaimed() const
{
	return cells_claimed;
}

