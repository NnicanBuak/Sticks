#pragma once
#include <string>

using namespace std;

class Player
{
private:
	string name;
	int cells_marked;
public:
	string getName() const;
	Player(string name) : name(name), cells_marked(0) {};
	virtual ~Player() {};
};