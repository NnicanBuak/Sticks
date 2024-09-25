#pragma once
#include "GameBoard.h"


class GameBoard3 :
	public GameBoard
{
public:
	explicit GameBoard3(size_t grid_sizeX, size_t grid_sizeY);

	size_t getSidesTotal() const override;
	void draw() const override;
};