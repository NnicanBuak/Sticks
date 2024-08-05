#pragma once
#include <vector> 

using namespace std;


struct Cell {
	bool claimed = false;
	int player_id_claimed_by = 0;
};

struct SidesNode {
	bool right = false;
	bool down = false;
};

class Board {
private:
	vector<vector<Cell>> grid_cells;
	vector<vector<SidesNode>> grid_sides_nodes;
public:
	explicit Board(size_t size);
	explicit Board(size_t sizeX, size_t sizeY);
	~Board() {};

	vector<vector<Cell>> getGridCells() const;
	vector<Cell> getFlattenGridCells() const;

	vector<vector<SidesNode>> getGridNodeSides() const;
	vector<SidesNode> getFlattenGridNodesSides() const;

	bool hasEmptyCells() const;

	size_t getCellsSizeX() const;
	size_t getCellsSizeY() const;

	size_t getSidesNodesSizeX() const;
	size_t getSidesNodesSizeY() const;

	size_t getCellsTotal() const;
	size_t getSidesNodesTotal() const; 
	size_t getSidesTotal() const;
};