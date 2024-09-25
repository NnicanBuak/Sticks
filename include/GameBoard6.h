#pragma once
#include "GameBoard.h"

/*
cout << "  •----•          " << endl;
cout << " /      \\        " << endl;
cout << "•        •----•   " << endl;
cout << " \\      /      \\" << endl;
cout << "  •----•        • " << endl;
cout << " /      \\      / " << endl;
cout << "•        •----•   " << endl;
cout << " \\      /      \\" << endl;
cout << "  •----•        • " << endl;
cout << "        \\      / " << endl;
cout << "         •----•   " << endl;
*/
class GameBoard6 :
	public GameBoard
{
public:
	explicit GameBoard6(size_t grid_sizeX, size_t grid_sizeY);

	size_t getSidesTotal() const override;
	void draw() const override;
};