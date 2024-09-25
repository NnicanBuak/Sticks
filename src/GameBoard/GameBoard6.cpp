#include "../../include/GameBoard6.h"

 
GameBoard6::GameBoard6(size_t grid_sizeX, size_t grid_sizeY)
{
	this->N = 6;
	this->cells_grid = vector<vector<GridCell>>(grid_sizeX, vector<GridCell>(grid_sizeY));
	this->nodes_grid = vector<vector<GridNode>>(grid_sizeX - 1, vector<GridNode>(grid_sizeY - 1, GridNode(2)));
}

size_t GameBoard6::getSidesTotal() const
{
	return (getSidesNodesSizeX() * 2 - 1) * getSidesNodesSizeY() - getSidesNodesSizeX();
}

void GameBoard6::draw() const
{
    vector<vector<GridCell>> cells_grid = this->getCellsGrid();
    vector<vector<GridNode>> nodes_grid = this->getNodesGrid();

    int cellsSizeX = this->getCellsSizeX();
    int cellsSizeY = this->getCellsSizeY();

    for (int i = 0; i < cellsSizeY; ++i) {
        // Смещение для чётных строк
        bool isOffset = (i % 2 != 0);

        // 1. Отрисовка узлов и горизонтальных рёбер
        if (isOffset) {
            cout << " ";
        }
        for (int j = 0; j < cellsSizeX; ++j) {
            // Узел
            cout << "•";

            // Горизонтальные рёбра
            if (nodes_grid[i][j].getDirection(0)) {
                cout << "---";
            }
            else {
                cout << "   ";
            }
        }
        cout << "•" << endl;

        // 2. Отрисовка диагональных рёбер и ячеек
        if (i < cellsSizeY - 1) {
            if (isOffset) {
                cout << " "; // Смещение
            }

            for (int j = 0; j < cellsSizeX; ++j) {
                // Диагональные рёбра
                if (nodes_grid[i][j].getDirection(1)) {
                    cout << "/";
                }
                else {
                    cout << " ";
                }

                // Пространство для ячейки
                if (cells_grid[i][j].claimed) {
                    cout << " " << game->getPlayer(cells_grid[i][j].player_id_claimed_by)->getName() << " ";
                }
                else {
                    cout << "   ";
                }

                if (nodes_grid[i][j].getDirection(2)) {
                    cout << "\\";
                }
                else {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    // 3. Финальная строка узлов
    bool isOffset = (cellsSizeY % 2 != 0);
    if (isOffset) {
        cout << " ";
    }
    for (int j = 0; j < cellsSizeX; ++j) {
        cout << "•";
        if (nodes_grid[cellsSizeY - 1][j].getDirection(0)) {
            cout << "---";
        }
        else {
            cout << "   ";
        }
    }
    cout << "•" << endl;
}
