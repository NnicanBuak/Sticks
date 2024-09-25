#pragma once
#include "GameBoard.h"


class GameBoard4 :
	public GameBoard
{
public:
	explicit GameBoard4(size_t grid_sizeX, size_t grid_sizeY);

	size_t getSidesTotal() const override;
	void draw() const override;
};