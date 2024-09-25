#include "../../include/GridNode.h"
#include <stdexcept>
#include <string>


GridNode::GridNode(size_t N, const vector<bool>& initial_states) :
	directions_N(N),
	directions(initial_states.empty() ? vector<bool>(N) : initial_states)
{};

void GridNode::setDirection(size_t index, bool state)
{
	if (index >= directions.size()) {
		throw out_of_range("GridNode directions index out of range" + to_string(index));
	}
	directions[index] = state;
};

bool GridNode::getDirection(size_t index) const
{
	if (index >= directions.size()) {
		throw out_of_range("GridNode directions index out of range" + to_string(index));
		return false;
	}
	return directions[index];
};