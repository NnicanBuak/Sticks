#include "../include/Cell.h"


size_t Cell::getNumSides() const
{
	return num_sides;
}

bool Cell::getSideStatus(int side_num) const
{
	int value = sides_statuses.at(side_num).player_id;
	if (value == -1) return false;
	return true;
}

bool Cell::setSideStatus(int side_num, int player_id)
{
	if (side_num >= 0 && side_num < num_sides) {
		sides_statuses[side_num].player_id = player_id;
		return true;
	}
	return false;
}