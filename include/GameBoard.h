#pragma once
#include "SticksGame.h"
#include "GridCell.h"
#include "GridNode.h"
#include "flatten.h"
#include <array>
#include <vector>
#include <iostream>

using namespace std;


class GameBoard {
protected:
	SticksGame* game;
	size_t N;
	vector<vector<GridCell>> cells_grid;
	vector<vector<GridNode>> nodes_grid;
public:
	friend class SticksGame;

	GameBoard(SticksGame* game);
	virtual ~GameBoard() = default;

	virtual size_t getSidesTotal() const = 0;
	virtual void draw() const = 0;

	vector<vector<GridCell>> getCellsGrid() const;
	vector<vector<GridNode>> getNodesGrid() const;

	vector<GridCell> getCellsFlattenGrid() const;
	vector<GridNode> getNodesFlattenGrid() const;

	size_t getCellsSizeX() const;
	size_t getCellsSizeY() const;

	size_t getSidesNodesSizeX() const;
	size_t getSidesNodesSizeY() const;

	size_t getCellsTotal() const;
	size_t getSidesNodesTotal() const;
	
	bool hasEmptyCells() const;
};