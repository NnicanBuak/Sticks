#pragma once
#include <vector>
#include <map>

using namespace std;

struct Cell {
    size_t num_sides;
    map<int, bool> side_status;

    Cell(size_t num_sides) : num_sides(num_sides) {};
    ~Cell() {};
};

struct GameBoard {
    size_t size;
    size_t cell_size;
    vector<vector<Cell>> grid;

    GameBoard(size_t size, size_t cell_size) : size(size), cell_size(cell_size) {};
    ~GameBoard() {};
    vector<Cell> flatten() const;
};