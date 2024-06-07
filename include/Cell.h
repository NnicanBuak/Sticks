#pragma once
#include <map>

using namespace std;

class Cell {
private:
    size_t num_sides;
    // By default start side (0) - top
    map<int, int> sides_statuses; // {side_num, player_id}
public:
    int player_id_claimed_by = -1;

    size_t getNumSides() const;
    bool getSideStatus(int side_num) const;

    bool setSideStatus(int side_num, int player_id);

    Cell(size_t num_sides) : num_sides(num_sides)
    {
        for (int i = 0; i < num_sides; ++i) {
            sides_statuses[i] = false;
        }
    }
    Cell() : num_sides(0) {}
    ~Cell() {};
};