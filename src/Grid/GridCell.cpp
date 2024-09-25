#include "../../include/GridCell.h"


GridCell::GridCell(bool claim, int player_id_claim) :
	claimed(claim),
	player_id_claimed_by(player_id_claim)
{};
