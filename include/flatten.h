#pragma once
#include <vector>

using namespace std;


template <typename T>
vector<T> flatten(const vector<vector<T>>& V)
{
	size_t total_size = 0;
	for (const auto& sub : V) 
		total_size += sub.size();
	vector<T> result;
	result.reserve(total_size);
	for (const auto& sub : V)
		result.insert(result.end(), sub.begin(), sub.end());
	return result;
}