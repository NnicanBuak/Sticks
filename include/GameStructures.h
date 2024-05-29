#pragma once
#include <vector>
#include <map>

using namespace std;

struct Cell {
    size_t num_sides;
    map<int, bool> side_status;

    // Initialization
    Cell(size_t num_sides) : num_sides(num_sides) {
        for (int i = 0; i < num_sides; ++i) {
            side_status[i] = false;
        }
    }
};

struct GameBoard {
    size_t size;
    size_t cell_size;
    vector<vector<Cell>> grid;

    GameBoard(size_t size, size_t cell_size) : size(size), cell_size(cell_size)
    {
        // Initialization 2d matrix of Cells 
        grid.resize(size, vector<Cell>(size, Cell(cell_size)));
    }
};