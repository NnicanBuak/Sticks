#pragma once
#include <map>
#include <iostream>

using namespace std;

struct SideStatus {
    int player_id = -1;
    bool shared = false;
};

class Cell {
private:
    size_t num_sides;
    // By default start side (0) - top
    map<int, SideStatus> sides_statuses;
public:
    int player_id_claimed_by = -1;

    size_t getNumSides() const;
    bool getSideStatus(int side_num) const;

    bool setSideStatus(int side_num, int player_id);

    Cell(size_t num_sides) : num_sides(num_sides) {};
    ~Cell() {};
};