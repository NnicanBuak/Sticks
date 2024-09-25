#pragma once


class GridCell {
public:
	explicit GridCell(bool claim = false, int player_id_claim = 0);
	~GridCell() = default;

	bool claimed = false;
	int player_id_claimed_by = 0;
};