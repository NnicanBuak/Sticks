#pragma once
#include <vector>

using namespace std;


class GridNode
{
private:
	size_t directions_N;
	vector<bool> directions;
protected:
	void setDirection(size_t index, bool state);
public:
	friend class SticksGame;

	explicit GridNode(size_t N = 0, const vector<bool>& initial_states = {});
	~GridNode() = default;

	bool getDirection(size_t index) const;
};